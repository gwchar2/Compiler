#include "../include/AST/Expressions/ASTUnaryExprNode.h"

/* Constructor */
ASTUnaryExprNode::ASTUnaryExprNode( ASTNode* operand) :
    ASTNode(NodeType::UNARY_EXPR) , operand(operand),temp(""){}

/* Returns the operand */
ASTNode* ASTUnaryExprNode::getOperand() const {
    return operand;
}

/* Visitor constructor */
void ASTUnaryExprNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}
