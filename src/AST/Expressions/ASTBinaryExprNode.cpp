#include "../include/AST/Expressions/ASTBinaryExprNode.h"

ASTBinaryExprNode::ASTBinaryExprNode(BinaryOp op, ASTNode* left, ASTNode* right):
    ASTNode(NodeType::BINARY_EXPR),op(op),left(left),right(right){}


ASTBinaryExprNode::BinaryOp ASTBinaryExprNode::getOperator() const {
    return op;
}

ASTNode* ASTBinaryExprNode::getLeft() const {
    return left;
}

ASTNode* ASTBinaryExprNode::getRight() const {
    return right;
}

void ASTBinaryExprNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}