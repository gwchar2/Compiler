#ifndef AST_PROGRAM_ROOT_H
#define AST_PROGRAM_ROOT_H

#include "ASTNode.h"
#include "ASTVisitor.h"

class ASTBlockNode;


/* The main root node of the AST */
class ASTProgramRoot : public ASTNode {
    public:
        ASTProgramRoot(ASTNode* blockNode);

        ASTBlockNode* getMainBlock() const;

        void accept(ASTVisitor& visitor) override;
    
    private:
        ASTBlockNode* mainBlock;
};

#endif
