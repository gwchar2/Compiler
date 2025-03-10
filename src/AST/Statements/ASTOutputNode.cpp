#include "../include/AST/Statements/ASTOutputNode.h"

/******************************/
/******** Output Node *********/
/******************************/

/* Constructor */
ASTOutputNode::ASTOutputNode(ASTNode* expression,int line_number) : 
    ASTNode(NodeType::OUTPUT, line_number), expression(expression){}

/* visitor */
void ASTOutputNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}


/* Gets the expression node */
ASTNode* ASTOutputNode::getExpression() const {
    return expression;
}

