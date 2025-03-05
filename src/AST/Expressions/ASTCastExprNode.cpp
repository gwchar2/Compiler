#include "../include/AST/Expressions/ASTCastExprNode.h"

/* Constructor */
ASTCastExprNode::ASTCastExprNode(ActionType type, ASTNode* operand) :
    ASTNode(NodeType::CAST_EXPR), castType(type), operand(operand), temp(""){}

/* Returns the type of cast inflicted*/
ActionType ASTCastExprNode::getCastType() const {
    return castType;
}

/* Returns the operand node */
ASTNode* ASTCastExprNode::getOperand() const {
    return operand;
}

/* Sets the temporary value to be used for holding a result */
void ASTCastExprNode::setTemp(const std::string& temp) {
    this -> temp = temp;
}

/* Visitor */
void ASTCastExprNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}