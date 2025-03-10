#include "../include/AST/Statements/ASTAssignNode.h"

/*****************************/
/******** ASSIGN NODE ********/
/*****************************/

/* Constructor */
ASTAssignNode::ASTAssignNode(const std::string& id, ASTNode* expression,int line_number) : 
    ASTNode(NodeType::ASSIGNMENT, line_number), id(id), expression(expression) {}

/* Visitor */
void ASTAssignNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}

/* Returns the ID assigned to the node (Left Hand Side)*/
const std::string& ASTAssignNode::getID() const {
    return id;
}

/* Returns the expression (Right Hand Side) */
ASTNode* ASTAssignNode::getExpression() const {
    return expression;
}

