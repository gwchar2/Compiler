#include "../include/AST/Expressions/ASTUnaryExprNode.h"

/*****************************/
/****** UNARY EXPR NODE ******/
/*****************************/

/* Constructor */
ASTUnaryExprNode::ASTUnaryExprNode( ASTNode* operand,int line_number) :
    ASTNode(NodeType::UNARY_EXPR,line_number) , operand(operand),temp(""){}

/* Visitor */
void ASTUnaryExprNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}

/* Returns the operand */
ASTNode* ASTUnaryExprNode::getOperand() const {
    return operand;
}


