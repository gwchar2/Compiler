#include "../include/AST/Statements/ASTInputNode.h"


/* Constructor */
ASTInputNode::ASTInputNode(const std::string& id) : 
    ASTNode(NodeType::INPUT), id(id){}


/* Gets the id / variable in the input */
const std::string& ASTInputNode::getID() const {
    return id;
}

/* Visitor */
void ASTInputNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}