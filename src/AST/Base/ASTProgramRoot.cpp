#include "../include/AST/Base/ASTProgramRoot.h"

/* Constructor for root */
ASTProgramRoot::ASTProgramRoot(ASTBlockNode* blockNode) : 
    ASTNode(NodeType::ROOT), mainBlock(blockNode){}

/* Retreives the main block (first node)*/
ASTBlockNode* ASTProgramRoot::getMainBlock() const {
    return mainBlock;
}

/* visitor */
void ASTProgramRoot::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

