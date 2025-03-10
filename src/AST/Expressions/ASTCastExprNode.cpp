#include "../include/AST/Expressions/ASTCastExprNode.h"

/*****************************/
/****** CAST EXPR NODE *******/
/*****************************/

/* Constructor */
ASTCastExprNode::ASTCastExprNode(ActionType type, ASTNode* operand,int line_number) :
    ASTNode(NodeType::CAST_EXPR,line_number), castType(type), operand(operand){}

/* Visitor */
void ASTCastExprNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}

/* Returns the type of cast inflicted*/
ActionType ASTCastExprNode::getCastType() const {
    return castType;
}

/* Returns the operand node */
ASTNode* ASTCastExprNode::getOperand() const {
    return operand;
}

/* Gets the type of data stored in this node */
DataType ASTCastExprNode::getDataType() const {
    return type;
}

/* Sets the type of data stored in this node */
void ASTCastExprNode::setDataType(DataType datatype) {
    type = datatype;
}

