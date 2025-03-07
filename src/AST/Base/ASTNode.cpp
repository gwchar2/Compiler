#include "../include/AST/Base/ASTNode.h"

/* Constructor */
ASTNode::ASTNode(NodeType type) : type(type){}

/* Get type func */
ASTNode::NodeType ASTNode::getType() const {
    return type;
}

/* Sets the temporary value to be used for holding a result */
void ASTNode::setTemp(const std::string& temp) {
    this -> temp = temp;
}

const std::string& ASTNode::getTemp() const {
    return temp;
}
/* Destructor */
ASTNode::~ASTNode() {}