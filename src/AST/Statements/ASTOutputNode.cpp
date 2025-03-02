#include "../include/AST/Statements/ASTOutputNode.h"


/* Constructor */
ASTOutputNode::ASTOutputNode(ASTNode* expression) : 
    ASTNode(NodeType::OUTPUT), expression(expression){}

/* Gets the expression node */
ASTNode* ASTOutputNode::getExpression() const {
    return expression;
}

/* visitor */
void ASTOutputNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}
