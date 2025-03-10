#ifndef AST_PROGRAM_ROOT_H
#define AST_PROGRAM_ROOT_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

class ASTBlockNode;


/* The main root node of the AST */
class ASTProgramRoot : public ASTNode {
    public:
        ASTProgramRoot(ASTNode* blockNode);                                 // Constructor
        void accept(ASTVisitor& visitor) override;                          // Visitor

        ASTBlockNode* getMainBlock() const;                                 // Main block
    
    
    private:
        ASTBlockNode* mainBlock;
};

#endif
