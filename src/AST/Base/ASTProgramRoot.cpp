#include "../include/AST/Base/ASTProgramRoot.h"

/* Constructor for root */
ASTProgramRoot::ASTProgramRoot(ASTNode* blockNode) : 
    ASTNode(NodeType::ROOT), mainBlock(dynamic_cast<ASTBlockNode*>(blockNode)){}

/* Retreives the main block (first node)*/
ASTBlockNode* ASTProgramRoot::getMainBlock() const {
    return mainBlock;
}

/* visitor */
void ASTProgramRoot::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

