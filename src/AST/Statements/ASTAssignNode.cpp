#include "../include/AST/Statements/ASTAssignNode.h"


ASTAssignNode::ASTAssignNode(const std::string& id, ASTNode* expression) : 
    ASTNode(NodeType::ASSIGNMENT), id(id), expression(expression) {}

const std::string& ASTAssignNode::getID() const {
    return id;
}

ASTNode* ASTAssignNode::getExpression() const {
    return expression;
}

void ASTAssignNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}