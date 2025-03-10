#include "../include/AST/Base/QuadGenerator.h"
/*****************************************/
/* Visiter Funcs for traversing the AST  */
/*****************************************/
/* Prints the instructions */
void QuadGenerator::printQuad(std::ostream& out){
    for (const auto& instruction : instructions)
        out << instruction.toString() << std::endl;
}

/* Generates the Quad code top-down */
void QuadGenerator::generateQuad(ASTProgramRoot* root){
    if (root) root -> accept(*this);
    instructions.emplace_back(QuadOp::HALT);            // Adds HALT command to the commands vector (Last command of program)
}

/* Visitor method for Root Node */
void QuadGenerator::visit(ASTProgramRoot& node) {
    if (node.getMainBlock())   node.getMainBlock() -> accept(*this);
}

/* Visitor method for Block Node, has no extra code generation */
void QuadGenerator::visit(ASTBlockNode& node){
    if (node.getStatementList())    node.getStatementList() -> accept(*this);
}

/* Visitor method for Statement Nodes. Itterates through the statement list and accepts each statement seperately. */
/* For example: 
    {
        x = 5;
        y = x + 3;
        output(y);
    }
    Will Envoke : accept(assign), accept(assign), accept(output)
    */
void QuadGenerator::visit(ASTStatementListNode& node) {
    for (ASTNode* stmt : node.getStatements()){
        if (stmt) {
            stmt -> accept(*this);
        }
    }
}

/* Input Node visitor */
/* input(ID) */
void QuadGenerator::visit(ASTInputNode& node) {
    if (globalScope.getSymbol(node.getID()).getType() == DataType::FLOAT) 
        instructions.emplace_back(QuadOp::RINP,node.getID());
    else instructions.emplace_back(QuadOp::IINP,node.getID());

}

/* output(expression)*/
/* Expression can be either : 
    - ASTBinaryExprNode (exp ADDOP term)
    - ASTBinaryExprNode (term MULOP factor)
    - ASTCastExprNode  / ASTIdentifierNode / ASTLiteralNode */
void QuadGenerator::visit(ASTOutputNode& node) {	
    /* We first visit the node */
    if(node.getExpression()) node.getExpression() -> accept(*this);
    Symbol& temp = globalScope.getSymbol(node.getExpression() -> getTemp());

    /* Get the temp holding the result, and print it according to type */
    if (node.getExpression() -> getType() == ASTNode::NodeType::LITERAL){
        if (temp.getType() == DataType::FLOAT)
            instructions.emplace_back(QuadOp::RPRT,temp.getName());
        else instructions.emplace_back(QuadOp::IPRT,temp.getName());
    }else{
        if (temp.getType() == DataType::FLOAT)
            instructions.emplace_back(QuadOp::RPRT,temp.getName());
        else instructions.emplace_back(QuadOp::IPRT,temp.getName());
    }
    if (node.getExpression() -> getType() != ASTNode::NodeType::IDENTIFIER) globalScope.releaseTemp(node.getExpression() -> getTemp());

}

/* Visits if/else nodes. First traverses the condition, than makes code for main block and else.
After it makes the code, it returns and changes the placeholders with return address & else address */
void QuadGenerator::visit(ASTIfNode& node) {
    /* We visit the condition first */
    if (node.getCondition()) node.getCondition() -> accept(*this);
    
    /* We save a placeholder for jumping to else bracket if condition is not met. */
    instructions.emplace_back(QuadOp::JMPZ, "placeholder");
    instructions[instructions.size()-1].arg1 = instructions[instructions.size()-2].result;
    int to_else = instructions.size()-1;

    /* We push a new scope, main body bracket and pop it when done */
    globalScope.pushScope();
    node.getMainBlock() -> accept(*this);
    globalScope.popScope();

    /* We add an instruction to jump to the end of the else bracket (continue the code) */
    /* We save the location of it in the code, and we also save the location of the beginning of the else */
    instructions.emplace_back(QuadOp::JUMP,"placeholder");
    int to_end = instructions.size()-1;
    instructions[to_else].result = std::to_string(instructions.size()+1);
    
    /* push a new scope, and enter else block, pop when done */
    globalScope.pushScope();
    node.getElseBlock() -> accept(*this);
    globalScope.popScope();

    /* We save the address of the end of the else. */
    instructions[to_end].result = std::to_string(instructions.size()+1);
    
    /* Release excess temps */
    globalScope.releaseTemp(node.getCondition() -> getTemp()); 
    globalScope.releaseTemp(node.getMainBlock() -> getTemp());
    globalScope.releaseTemp(node.getElseBlock() -> getTemp());  

}

/* While node generator. It first generates the code of the condition, and adds a placeholder for the end of the code 
After generating the main block, it returns to specific address and places the exact address for a jump. */
void QuadGenerator::visit(ASTWhileNode& node) {
    /* We keep a placeholder for the condition */
    int condition = instructions.size()+1;

    /* We visit the condition first */
    if(node.getCondition()) node.getCondition() -> accept(*this);

    /* We add a placeholder jump to the end of the while loop - when we break out of the condition */
    instructions.emplace_back(QuadOp::JMPZ,"placeholder");
    instructions[instructions.size()-1].arg1 = instructions[instructions.size()-2].result;
    int condition_break = instructions.size()-1;

    /* We now traverse the while loop while adding new scopes */
    globalScope.pushScope();
    if (node.getBody()) node.getBody() -> accept(*this);
    globalScope.popScope();

    /* We need to add a jump back to the condition, and point the condition break address to here. */
    instructions.emplace_back(QuadOp::JUMP,std::to_string(condition));
    /* Place the break address (RA) past the empty space, but it doesn't really matter. */
    instructions[condition_break].result = std::to_string(instructions.size()+1);

    /* For all 'break' placeholders, we need to put the correct address to jump. */
    for (auto& instr : instructions) {
        if (instr.result == "break") {
            instr.op = QuadOp::JUMP;
            instr.result = std::to_string(instructions.size()+1);
        }
    }


    /* Release excess temps */
    globalScope.releaseTemp(node.getCondition() -> getTemp());
    globalScope.releaseTemp(node.getBody() -> getTemp());
}

/* Case list node generator. */
void QuadGenerator::visit(ASTCaseListNode& node) {
    int i = 0;
    if (!node.getCases().empty()){
        /* We traverse the pair <Literal, Statement List >*/
        for (auto& pair : node.getCases()) {
            ASTLiteralNode* caseValue = pair.first;
            ASTStatementListNode* caseBody = pair.second;

            /* We receive the value of the case */
            if (caseValue) caseValue->accept(*this);
            std::string caseTemp = caseValue->getTemp();
            std::string calcResult = globalScope.newTemp(DataType::INT);

            
            /* We compare the switch statement with the specific case. 
                If the case is not equal, we jump to next case.
                If case is equal, we perform the code. If the code has a break, we will break.
                If not, we will continue going! */
            instructions.emplace_back(QuadOp::IEQL, calcResult, switchTemp, caseTemp);
            instructions.emplace_back(QuadOp::JMPZ, casePlaceHolders[i + 1].first, calcResult);

            /* We implement a new scope and perform the case */
            globalScope.pushScope();
            if (caseBody) caseBody -> accept(*this);
            globalScope.popScope();

            /* We store the address of the end of the case, for jumping purposes. */
            casePlaceHolders[i + 1].second = instructions.size() + 1;
            i++;
        }
    }
}
/* Traverses each case and generates the code, 
later on returns to the beginning and fills in the correct jump addresses. */
void QuadGenerator::visit(ASTSwitchNode& node) {
    /* Entering a switch automatically enters a scope */
    globalScope.pushScope();
    /* We start with the condition for the switch */
    if (node.getCondition()) node.getCondition() -> accept(*this);
    std::string switchTemp = node.getCondition() -> getTemp();
    int initial_value = instructions.size()-1;
    
    /* Make a unique place holder for each case with default -1 value for placeholders */
    int numCases = node.getCaseList()->getCases().size();
    for (int i = 0; i < numCases; i++) 
        casePlaceHolders.emplace_back("placeholder" + std::to_string(i), -1);
    casePlaceHolders.emplace_back("default", -1);


    /* We make sure that the case temp is an int and not a float!! */
    if (globalScope.getSymbol(switchTemp).getType() == DataType::FLOAT){
		std::string temp = switchTemp;
        switchTemp = globalScope.newTemp(DataType::INT);
        instructions.emplace_back(QuadOp::RTOI,switchTemp,globalScope.getSymbol(temp).valStr());
        globalScope.releaseTemp(temp);
    }
    
	/* We visit the case list now */
	node.getCaseList() -> accept(*this);

    /* Now that we are done, we are left only with putting the default value */
    if (node.getDefaultCase()){
        globalScope.pushScope();
        if (node.getDefaultCase()) node.getDefaultCase() -> accept(*this);
        globalScope.popScope();
    }

    /* We save the break address (first address after switch case) */
    int break_address = instructions.size()+1;

    /* We now traverse through the addresses and for every placeholder we put its correct address. */
    for (auto& pair : casePlaceHolders){
        for (auto it = instructions.begin() + initial_value; it != instructions.end(); it++){
            if (it -> result == pair.first)    it -> result = std::to_string(pair.second);
            if (it -> result == "break")   it -> result = std::to_string(break_address);
        }
    }

    globalScope.popScope();
}

void QuadGenerator::visit(ASTBreakNode& node) {
    instructions.emplace_back(QuadOp::JUMP,"break");
}

/* Anything with 2 operands. + / * && || < > <= >= != == */
void QuadGenerator::visit(ASTBinaryExprNode& node) {
    /* We first visit left and right side, and get there temps. */
    ASTNode* lhs = node.getLeft();
    ASTNode* rhs = node.getRight();

    if (lhs) lhs -> accept(*this);
    if (rhs) rhs -> accept(*this);
    /* We now need to do type checking to see if they are both same types and than calculate result into result temp*/

    /* Perform the type checking & update to new reference */
    typeConversion(lhs,rhs);
    /* Now we perform the operation and save the result as intended */   
    performOperation(node, globalScope.getSymbol(lhs -> getTemp()), globalScope.getSymbol(rhs -> getTemp()));

    /* If there was a need for type conversion, we must return the nodes to the true value. */
    if (lhs -> getType() == ASTNode::NodeType::IDENTIFIER && dynamic_cast<ASTIdentifierNode*>(lhs) -> isCasted()){
        lhs -> setTemp(dynamic_cast<ASTIdentifierNode*>(lhs) -> getName());
        dynamic_cast<ASTIdentifierNode*>(lhs) -> setCasted(false);
    }
    if (rhs -> getType() == ASTNode::NodeType::IDENTIFIER && dynamic_cast<ASTIdentifierNode*>(rhs) -> isCasted()) {
        rhs -> setTemp(dynamic_cast<ASTIdentifierNode*>(rhs) -> getName());
        dynamic_cast<ASTIdentifierNode*>(rhs) -> setCasted(false);
    }
}   

/* If !(float) -> FLOAT will be transfered to INT before the NOT operation */
void QuadGenerator::visit(ASTUnaryExprNode& node) {
    if (node.getOperand()) node.getOperand() -> accept(*this);
    
    Symbol& expr = globalScope.getSymbol(node.getOperand()->getTemp());
    int exprVal = (expr.getType() == DataType::INT) 
                    ? std::get<int>(expr.getVal()) 
                    : static_cast<int>(std::get<float>(expr.getVal()));
    
    if (expr.getType() == DataType::FLOAT){
        /* We set the node result as a new temp, and cast the current expression result to it (from float to int) */
        node.setTemp(globalScope.newTemp(DataType::INT));
        globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(exprVal)));
        instructions.emplace_back(QuadOp::RTOI,node.getTemp(),expr.getName());
    } else {
        /*If it doesnt need a cast, we just set the temp to be the same temp as the expression,
        we will just assign it a new value */
        node.setTemp(expr.getName());
    }
                                                                                                    // Example: Row #5
    instructions.emplace_back(QuadOp::JMPZ,std::to_string(instructions.size()+4),node.getTemp());   // Row #6 : jump to 9 if equal to 0
    instructions.emplace_back(QuadOp::IASN,node.getTemp(),"0");                                     // Row #7 : assign 0 (since will be equal to 1)
    instructions.emplace_back(QuadOp::JUMP,std::to_string(instructions.size()+3));                  // Row #8 : jump to 10 
    instructions.emplace_back(QuadOp::IASN,node.getTemp(),"1");                                     // Row #9 : assign 1 
                                                                                                    // Row #10: continue instructions 

}

/* Cast Node can have an operand of types : 
- ASTBinaryExprNode
- term -> factor -> ASTIdentifierNode / ASTLiteralNode / ASTCastExprNode 
ITOR D B     D:= real(B)
RTOI A E     A:= integer(E)
*/
void QuadGenerator::visit(ASTCastExprNode& node) {
    /* We first visit the operand */
    if (node.getOperand()) node.getOperand() -> accept(*this);
    /* Handle the cast */
    if (node.getCastType() == ActionType::ACTION_CASTFLOAT){
        node.setTemp(globalScope.newTemp(DataType::FLOAT));
        if (globalScope.getSymbol(node.getOperand() -> getTemp()).getType() != DataType::FLOAT){
            node.setTemp(globalScope.newTemp(DataType::FLOAT));
            /* We set the value of new temp to be the value of old temp, but casted to float. */
            globalScope.getSymbol(node.getTemp()).setVal(static_cast<float>(std::get<int>(globalScope.getSymbol(node.getOperand() -> getTemp()).getVal())));
        } else {
            globalScope.getSymbol(node.getTemp()).setVal(globalScope.getSymbol(node.getOperand() -> getTemp()).getVal());
        }
    } else {
        node.setTemp(globalScope.newTemp(DataType::INT));
        if (globalScope.getSymbol(node.getOperand() -> getTemp()).getType() != DataType::INT){
            node.setTemp(globalScope.newTemp(DataType::INT));
            /* We set the value of new temp to be the value of old temp, but casted to int. */
            globalScope.getSymbol(node.getTemp()).setVal(static_cast<int>(std::get<float>(globalScope.getSymbol(node.getOperand() -> getTemp()).getVal())));
        }else {
            globalScope.getSymbol(node.getTemp()).setVal(globalScope.getSymbol(node.getOperand() -> getTemp()).getVal());
            
        }
    }

    if (node.getOperand() -> getType() != ASTNode::NodeType::IDENTIFIER)    globalScope.releaseTemp(node.getOperand() -> getTemp());
}

/* Generates the Quad for Assign Nodes. 
For Example :
    y = x+3 
    will generate BinaryExprNode(x+3) and than Assign(y = x+3) 
First it checks if the expression node is a literal or an identifier. If it is, than it acts as an immediate value.
If it isn't, it requires a temporary value to be emitted, and to calculate the instructions for it.
Afterwords we will calculate the assign together with the temporary value.
*/
void QuadGenerator::visit(ASTAssignNode& node) {

    /* First we visit the expression */
    if (node.getExpression()) node.getExpression() -> accept(*this);
    Symbol& lhs = globalScope.getSymbol(node.getID());
    Symbol& rhs = globalScope.getSymbol(node.getExpression() -> getTemp());
    /* If we assign into a float, everything is possible */
    if (lhs.getType() == DataType::FLOAT){
        /* if RHS is a float, we just assign it */
        if (rhs.getType() == DataType::FLOAT){
            lhs.setVal(rhs.getVal());
            instructions.emplace_back(QuadOp::RASN,lhs.getName(),rhs.valStr());
        }else {
            /* We need to convert the int to a float first */
            std::string temp = globalScope.newTemp(DataType::FLOAT);
            lhs.setVal(std::variant<int,float>(static_cast<float>(std::get<int>(rhs.getVal()))));

            /* Implement the instructions, int -> float, assign float -> float */
            instructions.emplace_back(QuadOp::ITOR,temp,rhs.getName());
            instructions.emplace_back(QuadOp::RASN,lhs.getName(),temp);

            /* Release the temp */
            globalScope.releaseTemp(temp);
        }
    } else {
        /* If RHS is an INT we just assign it */
        if (rhs.getType() == DataType::INT){
            lhs.setVal(rhs.getVal());
            instructions.emplace_back(QuadOp::IASN,lhs.getName(),rhs.valStr()); 
        } else {
            /* We need to convert the float to an int */
            std::string temp = globalScope.newTemp(DataType::INT);
            lhs.setVal(std::variant<int,float>(static_cast<int>(std::get<float>(rhs.getVal()))));

            /* Implement the instructions, float -> int , assign int -> int */
            instructions.emplace_back(QuadOp::RTOI,temp,rhs.getName());
            instructions.emplace_back(QuadOp::IASN,lhs.getName(),temp);

            /* Release the temp */
            globalScope.releaseTemp(temp);
        }
    }

    if (node.getExpression() -> getType() != ASTNode::NodeType::IDENTIFIER) globalScope.releaseTemp(rhs.getName());


}

/* Checks if the ID Exists. If not, runtime error. If does, we save the temp name as it. */
void QuadGenerator::visit(ASTIdentifierNode& node) {
    node.setTemp(node.getName());
}

/* We first search if such a symbol already exists with same value before doing any commands */
void QuadGenerator::visit(ASTLiteralNode& node) {
    node.setTemp(globalScope.newTemp((node.isFloat() ? DataType::FLOAT : DataType::INT)));

    /* It technically matches a temp for it, but the instruction is not shown */
    instructions.emplace_back((node.isInt() ? QuadOp::IASN : QuadOp::RASN),node.getTemp(),node.getValueAsString());
    globalScope.getSymbol(node.getTemp()).setVal(node.getValue());
}




/***********************************/
/************ HELPERS **************/
/***********************************/

/* Handles the convertion of one of the temporaries to int or float */
void QuadGenerator::typeConversion(ASTNode* lhsNode, ASTNode* rhsNode){
    /* Converts the right hand side to float */
    if (globalScope.getSymbol(lhsNode->getTemp()).getType() == DataType::FLOAT 
        && globalScope.getSymbol(rhsNode->getTemp()).getType() == DataType::INT){

        /* Make a new temp with the new data type */
        std::string old_temp = rhsNode -> getTemp();
        rhsNode -> setTemp(globalScope.newTemp((DataType::FLOAT)));
        
        /* Place the conversion instruction on the stack */
        if (rhsNode -> getType() == ASTNode::NodeType::IDENTIFIER)
            instructions.emplace_back(QuadOp::ITOR, rhsNode->getTemp(), old_temp);
        else 
            instructions.emplace_back(QuadOp::ITOR, rhsNode->getTemp(), globalScope.getSymbol(old_temp).valStr());
            
        
        /* Transfer the data from old temp to converted temp */
        std::variant<int,float> val = static_cast<float>(std::get<int>(globalScope.getSymbol(old_temp).getVal()));            
        globalScope.getSymbol(rhsNode->getTemp()).setVal(val);

        /* If the nodes are not identifiers, we can release the temporaries they are holding. 
        If they are, we can not release the "temporary" because it is a predefined variable!! */
        if (rhsNode -> getType() != ASTNode::NodeType::IDENTIFIER) globalScope.releaseTemp(old_temp);
        else dynamic_cast<ASTIdentifierNode*>(rhsNode) -> setCasted(true);
    } 
    /* Converts the left hand side to float */
    else if (globalScope.getSymbol(lhsNode->getTemp()).getType() == DataType::INT 
        && globalScope.getSymbol(rhsNode->getTemp()).getType() == DataType::FLOAT){
        
        /* Make a new temp with the new data type */
        std::string old_temp = lhsNode -> getTemp();
        lhsNode -> setTemp(globalScope.newTemp(DataType::FLOAT));

        /* Place the conversion instruction on the stack */
        if (lhsNode -> getType() == ASTNode::NodeType::IDENTIFIER)
            instructions.emplace_back(QuadOp::ITOR, lhsNode -> getTemp(), old_temp);
        else 
            instructions.emplace_back(QuadOp::ITOR, lhsNode -> getTemp(), globalScope.getSymbol(old_temp).valStr());
        
        /* Transfer the data from old temp to converted temp */
        std::variant<int,float> val = static_cast<float>(std::get<int>(globalScope.getSymbol(old_temp).getVal()));            
        globalScope.getSymbol(lhsNode->getTemp()).setVal(val);                                                                          
        
        /* If the nodes are not identifiers, we can release the temporaries they are holding. 
        If they are, we can not release the "temporary" because it is a predefined variable!! */
        if (lhsNode -> getType() != ASTNode::NodeType::IDENTIFIER) globalScope.releaseTemp(old_temp);
        else dynamic_cast<ASTIdentifierNode*>(lhsNode) -> setCasted(true);
    }
}

/* Performs the correct operation (Places the correct code on the stack) */
void QuadGenerator::performOperation(ASTBinaryExprNode& node, Symbol& lhsSymbol, Symbol& rhsSymbol){

    node.setTemp((lhsSymbol.getType() == DataType::FLOAT && node.getOperator() > 8) 
            ? globalScope.newTemp(DataType::FLOAT) 
            : globalScope.newTemp(DataType::INT));
    
    /* Temps for holding the intermediate results */
    std::string temp1 = globalScope.newTemp(DataType::INT);    
    std::string temp2 = globalScope.newTemp(DataType::INT);
    Symbol& temp1Symbol = globalScope.getSymbol(temp1);
    Symbol& temp2Symbol = globalScope.getSymbol(temp2);
    
    /* We perform the action according to the operand types */
    if (lhsSymbol.getType() == DataType::INT) {
        int lhsVal = std::get<int>(lhsSymbol.getVal());
        int rhsVal = std::get<int>(rhsSymbol.getVal());

        switch (node.getOperator()) {
            case ActionType::ADD: 
                /* Calculate result */
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,lhsVal + rhsVal));
                instructions.emplace_back(QuadOp::IADD,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::SUB: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,lhsVal - rhsVal)); 
                instructions.emplace_back(QuadOp::ISUB,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::MUL: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,lhsVal * rhsVal)); 
                instructions.emplace_back(QuadOp::IMLT,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::DIV: 
                /* If we divide by 0, we input result 0 */
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(rhsVal != 0) ? lhsVal / rhsVal : 0)); 
                instructions.emplace_back(QuadOp::IDIV,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::CMP_LT: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal < rhsVal))); 
                instructions.emplace_back(QuadOp::ILSS,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::CMP_GT: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal > rhsVal))); 
                instructions.emplace_back(QuadOp::IGRT,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::CMP_NE: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal != rhsVal)));  
                instructions.emplace_back(QuadOp::INQL,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::CMP_EQ: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal == rhsVal))); 
                instructions.emplace_back(QuadOp::IEQL,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::CMP_LTE: {
                /* Calculate the result */
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal <= rhsVal) ? 1 : 0));  
                temp1Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal < rhsVal) ? 1 : 0));
                temp2Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal == rhsVal) ? 1 : 0));
                /* We put the instructions for less than, equal */
                instructions.emplace_back(QuadOp::ILSS, temp1, lhsSymbol.valStr(),rhsSymbol.valStr());
                instructions.emplace_back(QuadOp::IEQL, temp2, lhsSymbol.valStr(),rhsSymbol.valStr());
                /* We calculate if temp1 + temp2 greater than 0, if yes that means that one of them at least is true */
                instructions.emplace_back(QuadOp::IADD, node.getTemp(), temp1, temp2);
                instructions.emplace_back(QuadOp::INQL, node.getTemp(), node.getTemp(), "0");
                break;
            }
            case ActionType::CMP_GTE: {
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal >= rhsVal) ? 1 : 0));  
                temp1Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal > rhsVal) ? 1 : 0));
                temp2Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal == rhsVal) ? 1 : 0));
                /* We put the instructions for greater than, equal */
                instructions.emplace_back(QuadOp::IGRT, temp1, lhsSymbol.valStr(),rhsSymbol.valStr());
                instructions.emplace_back(QuadOp::IEQL, temp2, lhsSymbol.valStr(),rhsSymbol.valStr());
                /* We calculate if temp1 + temp2 greater than 0, if yes that means that one of them at least is true */
                instructions.emplace_back(QuadOp::IADD, node.getTemp(), temp1, temp2);
                instructions.emplace_back(QuadOp::INQL, node.getTemp(), node.getTemp(), "0");
                break;
            }
            case ActionType::LOGICAL_OR: {
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal || rhsVal) ? 1 : 0));  
                temp1Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal + rhsVal)));
                /* We calculate if lhs + rhs > 0 (0 = false, 1< is true ) */
                instructions.emplace_back(QuadOp::IADD, temp1, lhsSymbol.valStr(),rhsSymbol.valStr());
                instructions.emplace_back(QuadOp::INQL, node.getTemp(), temp1, "0");
                break;
            }
            case ActionType::LOGICAL_AND: {
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal && rhsVal) ? 1 : 0));  
                temp1Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal * rhsVal)));
                /* We calculate if lhs * rhs != 0 (0 = false, 1< is true ) */
                instructions.emplace_back(QuadOp::IMLT, temp1, lhsSymbol.valStr(),rhsSymbol.valStr());
                instructions.emplace_back(QuadOp::INQL, node.getTemp(), temp1, "0");
                break;
            }
            default: throw std::runtime_error("Unsupported operation for INT type");
        }
        
    } else {
        float lhsVal = std::get<float>(lhsSymbol.getVal());
        float rhsVal = std::get<float>(rhsSymbol.getVal());

        switch (node.getOperator()) {
            case ActionType::ADD: 
                /* Calculate result */
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<float>,lhsVal + rhsVal));
                instructions.emplace_back(QuadOp::RADD,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::SUB: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<float>,lhsVal - rhsVal)); 
                instructions.emplace_back(QuadOp::RSUB,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::MUL: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<float>,lhsVal * rhsVal)); 
                instructions.emplace_back(QuadOp::RMLT,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::DIV: 
                /* If we divide by 0, we input result 0 */
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<float>,(rhsVal != 0) ? lhsVal / rhsVal : 0.0)); 
                instructions.emplace_back(QuadOp::RDIV,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::CMP_LT: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal < rhsVal))); 
                instructions.emplace_back(QuadOp::RLSS,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::CMP_GT: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal > rhsVal) ? 1 : 0)); 
                instructions.emplace_back(QuadOp::RGRT,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::CMP_NE: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal != rhsVal) ? 1 : 0));  
                instructions.emplace_back(QuadOp::RNQL,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::CMP_EQ: 
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal == rhsVal) ? 1 : 0)); 
                instructions.emplace_back(QuadOp::REQL,node.getTemp(),lhsSymbol.getName(),rhsSymbol.getName());
                break;
            case ActionType::CMP_LTE: {
                /* Calculate the result */
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal <= rhsVal) ? 1 : 0));  
                temp1Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal < rhsVal) ? 1 : 0));
                temp2Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal == rhsVal) ? 1 : 0));
                /* We put the instructions for less than, equal */
                instructions.emplace_back(QuadOp::RLSS, temp1, lhsSymbol.valStr(), rhsSymbol.valStr());
                instructions.emplace_back(QuadOp::REQL, temp2, lhsSymbol.valStr(), rhsSymbol.valStr());
                /* We calculate if temp1 + temp2 greater than 0, if yes that means that one of them at least is true */
                instructions.emplace_back(QuadOp::IADD, node.getTemp(), temp1, temp2);
                instructions.emplace_back(QuadOp::INQL, node.getTemp(), node.getTemp(), "0");
                break;
            }
            case ActionType::CMP_GTE: {
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal >= rhsVal) ? 1 : 0));  
                temp1Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal > rhsVal) ? 1 : 0));
                temp2Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal == rhsVal) ? 1 : 0));
                /* We put the instructions for greater than, equal */
                instructions.emplace_back(QuadOp::RGRT, temp1, lhsSymbol.valStr(),rhsSymbol.valStr());
                instructions.emplace_back(QuadOp::REQL, temp2, lhsSymbol.valStr(),rhsSymbol.valStr());
                /* We calculate if temp1 + temp2 greater than 0, if yes that means that one of them at least is true */
                instructions.emplace_back(QuadOp::IADD, node.getTemp(), temp1, temp2);
                instructions.emplace_back(QuadOp::INQL, node.getTemp(), node.getTemp(), "0");
                break;
            }
            case ActionType::LOGICAL_OR: {
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal || rhsVal) ? 1 : 0)); 
                temp1Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal + rhsVal)));
                /* We calculate if lhs + rhs > 0 (0 = false, 1< is true ) */
                instructions.emplace_back(QuadOp::RADD, temp1, lhsSymbol.valStr(),rhsSymbol.valStr());
                instructions.emplace_back(QuadOp::INQL, node.getTemp(), temp1, "0");
                break;
            }
            case ActionType::LOGICAL_AND: {
                globalScope.getSymbol(node.getTemp()).setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal && rhsVal) ? 1 : 0));  
                temp1Symbol.setVal(std::variant<int,float>(std::in_place_type<int>,(lhsVal * rhsVal)));
                /* We calculate if lhs * rhs != 0 (0 = false, 1< is true ) */
                instructions.emplace_back(QuadOp::RMLT, temp1, lhsSymbol.valStr(),rhsSymbol.valStr());
                instructions.emplace_back(QuadOp::INQL, node.getTemp(), temp1, "0");
                break;
            }
            default: throw std::runtime_error("Unsupported operation for INT type");
        }
    }

    globalScope.releaseTemp(temp1);
    globalScope.releaseTemp(temp2);
    if (node.getLeft()->getType() != ASTNode::NodeType::IDENTIFIER) globalScope.releaseTemp(lhsSymbol.getName());
    if (node.getRight()->getType() != ASTNode::NodeType::IDENTIFIER) globalScope.releaseTemp(rhsSymbol.getName());
}
