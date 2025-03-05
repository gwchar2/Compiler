#include "../include/AST/Expressions/ASTUnaryExprNode.h"

/* Constructor */
ASTUnaryExprNode::ASTUnaryExprNode( ASTNode* operand) :
    ASTNode(NodeType::UNARY_EXPR) , operand(operand),temp(""){}

/* Returns the operand */
ASTNode* ASTUnaryExprNode::getOperand() const {
    return operand;
}

void ASTUnaryExprNode::setTemp(const std::string& temp){
    this -> temp = temp;
}

/* Visitor constructor */
void ASTUnaryExprNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}
