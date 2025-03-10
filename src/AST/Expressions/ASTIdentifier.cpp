#include "../include/AST/Expressions/ASTIdentifierNode.h"

/*****************************/
/****** Identifier Node ******/
/*****************************/

/* Constructor func */
ASTIdentifierNode::ASTIdentifierNode(const std::string& name,int line_number) :
    ASTNode(NodeType::IDENTIFIER,line_number), name(name) {}

/* Visitor */
void ASTIdentifierNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

/* Returns the ID */
const std::string& ASTIdentifierNode::getName() const {
    return name;
}

/* Checks if this node went through casting.
    We need this to properly make sure we do not delete it afterwords. */
bool ASTIdentifierNode::isCasted() {
    return casted;
}

/* Sets the casted boolean */
void ASTIdentifierNode::setCasted(bool status){
    casted = status;
}

