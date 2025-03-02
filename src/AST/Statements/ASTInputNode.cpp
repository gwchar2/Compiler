#include "../include/AST/Statements/ASTInputNode.h"


/* Constructor */
ASTInputNode::ASTInputNode(ASTNode* identifier) : 
    ASTNode(NodeType::INPUT), identifier(identifier){}


/* Gets the id / variable in the input */
ASTNode* ASTInputNode::getIdentifier() const {
    return identifier;
}

/* Visitor */
void ASTInputNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}