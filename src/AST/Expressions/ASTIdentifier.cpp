#include "../include/AST/Expressions/ASTIdentifierNode.h"

/* Constructor func */
ASTIdentifierNode::ASTIdentifierNode(const std::string& name) :
    ASTNode(NodeType::IDENTIFIER), name(name) {}

/* Returns the ID */
const std::string& ASTIdentifierNode::getName() const {
    return name;
}

/* Visitor */
void ASTIdentifierNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}