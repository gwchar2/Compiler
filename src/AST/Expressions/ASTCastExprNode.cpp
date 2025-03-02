#include "../include/AST/Expressions/ASTCastExprNode.h"

/* Constructor */
ASTCastExprNode::ASTCastExprNode(CastType type, ASTNode* operand) :
    ASTNode(NodeType::CAST_EXPR), castType(type), operand(operand){}

/* Returns the type of cast inflicted*/
ASTCastExprNode::CastType ASTCastExprNode::getCastType() const {
    return castType;
}

/* Returns the operand node */
ASTNode* ASTCastExprNode::getOperand() const {
    return operand;
}

/* Visitor */
void ASTCastExprNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}