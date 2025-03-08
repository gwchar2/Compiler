#include "../include/AST/ControlFlow/ASTWhileNode.h"

/* While Node Constructor */
ASTWhileNode::ASTWhileNode(ASTNode* condition, ASTNode* body) :
    ASTNode(NodeType::WHILE_STMT),condition(condition),body(body) {}

ASTNode* ASTWhileNode::getCondition() const {
    return condition;
}

ASTNode* ASTWhileNode::getBody() const {
    return body;
}


void ASTWhileNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}