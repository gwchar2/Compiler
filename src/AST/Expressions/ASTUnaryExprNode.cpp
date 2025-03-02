#include "../include/AST/Expressions/ASTUnaryExprNode.h"

/* Constructor */
ASTUnaryExprNode::ASTUnaryExprNode(UnaryOp op, ASTNode* operand) :
    ASTNode(NodeType::UNARY_EXPR), op(op), operand(operand){}

/* Returns the Op (NOT)*/
ASTUnaryExprNode::UnaryOp ASTUnaryExprNode::getOperator() const {
    return op;
}

/* Returns the operand */
ASTNode* ASTUnaryExprNode::getOperand() const {
    return operand;
}

/* Visitor constructor */
void ASTUnaryExprNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}
