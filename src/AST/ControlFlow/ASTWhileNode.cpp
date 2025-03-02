#include "../include/AST/ControlFlow/ASTWhileNode.h"


ASTWhileNode::ASTWhileNode(ASTNode* condition, ASTNode* body,int cond_address, int body_address, int return_address) :
    ASTNode(NodeType::WHILE_STMT), condition(condition), body(body), cond_address(cond_address),body_address(body_address), return_address(-1) {}

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