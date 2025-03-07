#include "../include/AST/Base/QuadGenerator.h"
#include <iostream>



/*****************************************/
/* Visiter Funcs for traversing the AST */
/*****************************************/

/* Generates the Quad code top-down */
void QuadGenerator::generateQuad(ASTProgramRoot* root){
    try {
        root -> accept(*this);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
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

}

/* Output Node visitor. Creates a temp for expression, afterwords prints the temp. */
/* output(expression)*/
/* Expression can be either : 
    - ASTBinaryExprNode (exp ADDOP term)
    - ASTBinaryExprNode (term MULOP factor)
    - ASTCastExprNode  / ASTIdentifierNode / ASTLiteralNode */
void QuadGenerator::visit(ASTOutputNode& node) {

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

/* Anything with 2 operands. + / * && || < > <= >= != == */
void QuadGenerator::visit(ASTBinaryExprNode& node) {
    
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

}

/* Checks if the ID Exists. If not, runtime error. If does, we save the temp name as it. */
void QuadGenerator::visit(ASTIdentifierNode& node) {
    if (!globalScope.exists(node.getName())){
        node.setTemp("");
        throw std::runtime_error("Error!: The identifier " + node.getName() + " does not exist!");
    }
    node.setTemp(node.getName());
}


/* We first search if such a symbol already exists with same value before doing any commands */
void QuadGenerator::visit(ASTLiteralNode& node) {
    auto tempOpt = globalScope.getSymbolByValue(node.getValue());

    std::string temp;
    /* If a symbol has been found, we point to it */
    if (tempOpt)    temp = *tempOpt;
    /* If not, we make a new temp and add it to the scope */
    else {
        temp = globalScope.newTemp();
        QuadOp op = node.isInt() ? QuadOp::IASN : QuadOp::RASN;
        instructions.emplace_back(op,temp,node.getValueAsString());
        Symbol& symbol = globalScope.insert(temp,node.isInt() ? DataType::INT : DataType::FLOAT);
        symbol.setVal(node.getValue());
    }

    /* We set the nodes temp as temp */
    node.setTemp(temp);
}