#include "../include/AST/Statements/ASTProgramRoot.h"

/*****************************/
/***** Program Root Node *****/
/*****************************/

/* Constructor for root */
ASTProgramRoot::ASTProgramRoot(ASTNode* blockNode) : 
    ASTNode(NodeType::ROOT,-1), mainBlock(dynamic_cast<ASTBlockNode*>(blockNode)){}

/* Visitor */
void ASTProgramRoot::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

/* Retreives the main block (first node)*/
ASTBlockNode* ASTProgramRoot::getMainBlock() const {
    return mainBlock;
}



