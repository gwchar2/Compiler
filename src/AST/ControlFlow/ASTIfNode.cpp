#include "../include/AST/ControlFlow/ASTIfNode.h"


/* Constructor */
ASTIfNode::ASTIfNode(ASTNode* condition, ASTNode* mainBlock, ASTNode* elseBlock) :
    ASTNode(NodeType::IF_STMT), condition(condition), mainBlock(mainBlock), elseBlock(elseBlock){}

ASTNode* ASTIfNode::getCondition() const {
    return condition;
}

ASTNode* ASTIfNode::getMainBlock() const {
    return mainBlock;
}

ASTNode* ASTIfNode::getElseBlock() const {
    return elseBlock;
}

void ASTIfNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}