#include "../include/AST/ControlFlow/ASTIfNode.h"
/******************************/
/********** IF NODE ***********/
/******************************/

/* Constructor */
ASTIfNode::ASTIfNode(ASTNode* condition, ASTNode* mainBlock, ASTNode* elseBlock,int line_number) :
    ASTNode(NodeType::IF_STMT,line_number), condition(condition), mainBlock(mainBlock), elseBlock(elseBlock){}

/* Visitor */
void ASTIfNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

/* Returns the condition node */
ASTNode* ASTIfNode::getCondition() const {
    return condition;
}

/* Returns the main block node */
ASTNode* ASTIfNode::getMainBlock() const {
    return mainBlock;
}

/* Returns the else block node */
ASTNode* ASTIfNode::getElseBlock() const {
    return elseBlock;
}

