#include "../include/AST/Statements/ASTInputNode.h"

/*****************************/
/******** INPUT NODE *********/
/*****************************/

/* Constructor */
ASTInputNode::ASTInputNode(const std::string& id,int line_number) : 
    ASTNode(NodeType::INPUT,line_number), id(id){}

/* Visitor */
void ASTInputNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

/* Gets the id / variable in the input */
const std::string& ASTInputNode::getID() const {
    return id;
}
