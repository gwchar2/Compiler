#include "../include/AST/Expressions/ASTBinaryExprNode.h"

/*****************************/
/***** Binary Expr Node ******/
/*****************************/

/* Constructor*/
ASTBinaryExprNode::ASTBinaryExprNode(ActionType op, ASTNode* left, ASTNode* right,int line_number):
    ASTNode(NodeType::BINARY_EXPR,line_number),op(op),left(left),right(right){}

/* Visitor */
void ASTBinaryExprNode::accept(ASTVisitor& visitor){
    visitor.visit(*this);
}

/* Returns the OP */
ActionType ASTBinaryExprNode::getOperator() const {
    return op;
}

/* Returns left hand side node */
ASTNode* ASTBinaryExprNode::getLeft() const {
    return left;
}

/* Returns right hand side node */
ASTNode* ASTBinaryExprNode::getRight() const {
    return right;
}


/* Returns ActionType representation for a string of actions */
ActionType get_operator_action(const std::string& op) {
    if (op == "+") return ActionType::ADD;
    else if (op == "-") return ActionType::SUB;
    else if (op == "*") return ActionType::MUL;
    else if (op == "/") return ActionType::DIV;
    else if (op == "<") return ActionType::CMP_LT;
    else if (op == ">") return ActionType::CMP_GT;
    else if (op == "<=") return ActionType::CMP_LTE;
    else if (op == ">=") return ActionType::CMP_GTE;
    else if (op == "!=") return ActionType::CMP_NE;
    else if (op == "==") return ActionType::CMP_EQ;
    return ActionType::INVALID;
}