#include "../include/AST/Base/ASTNode.h"

/* Constructor */
ASTNode::ASTNode(NodeType type) : type(type){}

/* Get type func */
ASTNode::NodeType ASTNode::getType() const {
    return type;
}


/* Destructor */
ASTNode::~ASTNode() {}