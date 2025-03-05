#include "../include/AST/Expressions/ASTBinaryExprNode.h"

ASTBinaryExprNode::ASTBinaryExprNode(ActionType op, ASTNode* left, ASTNode* right):
    ASTNode(NodeType::BINARY_EXPR),op(op),left(left),right(right), temp(""){}

ActionType ASTBinaryExprNode::getOperator() const {
    return op;
}

ASTNode* ASTBinaryExprNode::getLeft() const {
    return left;
}

ASTNode* ASTBinaryExprNode::getRight() const {
    return right;
}

void ASTBinaryExprNode::setTemp(const std::string& temp){
    this -> temp = temp;
}

const std::string& ASTBinaryExprNode::getTemp() const {
    return temp;
}

void ASTBinaryExprNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}