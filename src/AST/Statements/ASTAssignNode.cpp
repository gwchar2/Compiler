#include "../include/AST/Statements/ASTAssignNode.h"


ASTAssignNode::ASTAssignNode(ASTNode* left, ASTNode* right) : 
    ASTNode(NodeType::ASSIGNMENT), left(left), right(right) {}

ASTNode* ASTAssignNode::getLeft() const {
    return left;
}

ASTNode* ASTAssignNode::getRight() const {
    return right;
}

void ASTAssignNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}