#include "../include/AST/ControlFlow/ASTWhileNode.h"

/* While Node Constructor */
ASTWhileNode::ASTWhileNode(ASTNode* condition, ASTNode* body) :
    ASTNode(NodeType::WHILE_STMT), condition(condition), body(body), cond_address(-1),body_address(-1), return_address(-1) {}

ASTNode* ASTWhileNode::getCondition() const {
    return condition;
}

ASTNode* ASTWhileNode::getBody() const {
    return body;
}

int ASTWhileNode::getCondAddress() const {
    return cond_address;
}

int ASTWhileNode::getBodyAddress() const {
    return body_address;
}

int ASTWhileNode::getReturnAddress() const {
    return return_address;
}

void ASTWhileNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}