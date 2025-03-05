#include "../include/AST/Base/QuadGenerator.h"
#include <iostream>

/**********************************/
/* Constructor, Setters, Getters */
/**********************************/
/* Generates a new temp from free stack or new one */
std::string QuadGenerator::newTemp() {
    if (!freeTemps.empty()){
        std::string temp = freeTemps.top();
        freeTemps.pop();
        return temp;
    }
    return "t" + std::to_string(tempCounter++);
}

/* Releases a temporary by loading it on the stack */
void QuadGenerator::releaseTemp(std::string temp){
    freeTemps.push(temp);
    symbolTable.removeSymbol(temp);
}

/* Generates a new label */
std::string QuadGenerator::newLabel() {
    return "L" + std::to_string(labelCounter++);
}

/* Prints the Quad instructions */
void QuadGenerator::printQuad() {
    for (const auto& instr : instructions){
        std::cout << instr.toString() << std::endl;
    }
}

/*****************************************/
/* Visiter Funcs for traversing the AST */
/*****************************************/

/* Generates the Quad code top-down */
void QuadGenerator::generateQuad(ASTProgramRoot* root){
    root -> accept(*this);
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
    std::string ID = node.getID();
    DataType type = symbolTable.getSymbol(ID).getType();

    if (type == DataType::INT)  instructions.emplace_back(QuadOp::IINP,ID);
    else if (type == DataType::FLOAT)   instructions.emplace_back(QuadOp::RINP,ID);

}

/* Output Node visitor. Creates a temp for expression, afterwords prints the temp. */
/* output(expression)*/
/* Expression can be either : 
    - ASTBinaryExprNode (exp ADDOP term)
    - ASTBinaryExprNode (term MULOP factor)
    - ASTCastExprNode  / ASTIdentifierNode / ASTLiteralNode */
void QuadGenerator::visit(ASTOutputNode& node) {
    /* We get the expression node and its type */
    ASTNode* expr = node.getExpression();
    ASTNode::NodeType exprType = expr -> getType();
    
    std::variant<int,float> val;
    std::string ID;
    DataType type;
    switch (exprType){
        case ASTNode::NodeType::LITERAL:
        case ASTNode::NodeType::IDENTIFIER:
            if (exprType == ASTNode::NodeType::LITERAL) {
                val = dynamic_cast<ASTLiteralNode*>(expr)->getValue();
                type = (dynamic_cast<ASTLiteralNode*>(expr) -> isInt()) ? DataType::INT : DataType::FLOAT;
                ID = std::holds_alternative<int>(val) ? std::to_string(std::get<int>(val)) 
                                                      : std::to_string(std::get<float>(val));
            } 
            else if (exprType == ASTNode::NodeType::IDENTIFIER) {
                ID = dynamic_cast<ASTIdentifierNode*>(expr)->getName();
                type = symbolTable.getSymbol(ID).getType();
            }
            break;
        case ASTNode::NodeType::CAST_EXPR:
        case ASTNode::NodeType::BINARY_EXPR:
            ID = newTemp();
            if (exprType == ASTNode::NodeType::BINARY_EXPR) 
                dynamic_cast<ASTBinaryExprNode*>(expr) -> setTemp(ID);
            else dynamic_cast<ASTCastExprNode*>(expr) -> setTemp(ID);
            expr -> accept(*this);
            type = symbolTable.getSymbol(ID).getType();
            break;
    }
    /* We add the instruction */
    if (type == DataType::INT)  instructions.emplace_back(QuadOp::IPRT,ID);
    else if (type == DataType::FLOAT)   instructions.emplace_back(QuadOp::RPRT,ID);
    
    /* If it was a BinaryExprNode or a CastExprNode , we remove the temp from symbol table */
    if (exprType == ASTNode::NodeType::BINARY_EXPR || exprType == ASTNode::NodeType::CAST_EXPR) 
        releaseTemp(ID);

    
}

void QuadGenerator::visit(ASTIfNode& node) {
    // TODO: Implement if statement handling
}

void QuadGenerator::visit(ASTWhileNode& node) {
    // TODO: Implement while loop handling
}

void QuadGenerator::visit(ASTCaseListNode& node) {
    // TODO: Implement case list handling
}

void QuadGenerator::visit(ASTSwitchNode& node) {
    // TODO: Implement switch statement handling
}

void QuadGenerator::visit(ASTBreakNode& node) {
    // TODO: Implement break statement handling
}

void QuadGenerator::visit(ASTBinaryExprNode& node) {
    // TODO: Implement binary expression handling
}

void QuadGenerator::visit(ASTUnaryExprNode& node) {
    // TODO: Implement unary expression handling
}

/* Cast Node can have an operand of types : 
- ASTBinaryExprNode
- term -> factor -> ASTIdentifierNode / ASTLiteralNode / ASTCastExprNode 
ITOR D B     D:= real(B)
RTOI A E     A:= integer(E)
*/
void QuadGenerator::visit(ASTCastExprNode& node) {
    // If temp is not empty we must write the result to it, and put it in the symbol table!
    // we do not release the pre-determined temp! it will be done by father caller.
    // if we need our own temp -> we will also release it!
}

void QuadGenerator::visit(ASTIdentifierNode& node) {
    /* We do not really have anything to implement here.... Empty for now. */
}

void QuadGenerator::visit(ASTLiteralNode& node) {
    /* We do not really have anything to implement here.... Empty for now. */
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
    std::string left = node.getID();                                                    // Left side of assign is the ID saved in assign node.
    std::string right;                                                                  // Right side of assing
    DataType leftType = symbolTable.getSymbol(left).getType();                          // Holds the DataType of the left side 
    DataType rightType;                                                                 // DataType of right side 
    QuadOp op;                                                                          // Holds the final OpCode
    std::variant<int,float> val;                                                        // Holds the value of a literal node

    /* First we check what type of node we have in the assign expression */
    /* If it is a literal or an identifier, we treat it like an immediate */
    ASTNode* expression = node.getExpression();
    ASTNode::NodeType type = expression->getType();

    /* Now we itterate through the different type cases (type of node)*/
    switch (type) {
        /* For litterals or identifiers */
        case ASTNode::NodeType::LITERAL:
        case ASTNode::NodeType::IDENTIFIER: 
            if (type == ASTNode::NodeType::LITERAL) {
                val = dynamic_cast<ASTLiteralNode*>(expression)->getValue();
            } 
            else if (type == ASTNode::NodeType::IDENTIFIER) {
                right = dynamic_cast<ASTIdentifierNode*>(expression)->getName();
                val = symbolTable.getSymbol(right).getVal();
            }

            /* We assign right according to handle Assignment */
            right = handleAssignment(val, leftType, rightType, op);
            
            /* We update the symbol table and add the instruction */
            symbolTable.getSymbol(left).setVal(val);
            instructions.emplace_back(op, left, right);    
            break;
        
        /* For Binary expresions, Unary expressions, and Cast Expressions */
        case ASTNode::NodeType::BINARY_EXPR:
        case ASTNode::NodeType::CAST_EXPR: 
            /* We need to make a new temp variable and set it on the node */
            right = newTemp();

            if (type == ASTNode::NodeType::BINARY_EXPR) {
                dynamic_cast<ASTBinaryExprNode*>(expression)->setTemp(right);
            } else if (type == ASTNode::NodeType::CAST_EXPR) {
                dynamic_cast<ASTCastExprNode*>(expression)->setTemp(right);
            }
            
            expression->accept(*this);  

            /* After envoking visitor, we need to get the information of the new temp from the symbol table (its value) */
            rightType = symbolTable.getSymbol(right).getType();
            val = symbolTable.getSymbol(right).getVal();

            /* We handle the assigments according to the assistant func */
            right = handleAssignment(val, leftType, rightType, op);
            
            /* Update symbol table, add the instruction, and free the temp */
            symbolTable.getSymbol(left).setVal(val); 
            instructions.emplace_back(op, left, right);   
            releaseTemp(right);
            break;
        
        default: 
            std::cout << "Unknown node type in assignment." << std::endl;
            break;
    }
    /* Add the Quad Instruction to the instruction vector */

}





/***************************/
/* Code Generation Helpers */
/***************************/

/* Helper function that handles checks / assignments / opcode */
std::string QuadGenerator::handleAssignment(const std::variant<int, float>& val, const DataType& leftType, const DataType& rightType, QuadOp& outOp) {
    if (leftType == DataType::INT && rightType == DataType::INT) {
        outOp = QuadOp::IASN;
        return std::to_string(std::get<int>(val));
    } 
    else if (leftType == DataType::INT && rightType == DataType::FLOAT) {
        std::cout << "[FILE: " << __FILE__ << " LINE: " << __LINE__ << "] Error: can't assign float to int type." << std::endl;
        return "";
    } 
    else {
        outOp = QuadOp::RASN;
        return std::holds_alternative<float>(val) ? std::to_string(std::get<float>(val)) : std::to_string(std::get<int>(val));
    }
}












