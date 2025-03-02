#ifndef AST_ASSIGN_NODE_H
#define AST_ASSIGN_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"


class ASTAssignNode : public ASTNode {
    public:
        ASTAssignNode(ASTNode* left, ASTNode* right);       // Constructor
        void accept(ASTVisitor& visitor) override;          // Visitor func constructor

        ASTNode* getLeft() const;                       // Get left side
        ASTNode* getRight() const;                      // Get right side

    private:
        ASTNode* left;                                  // Left side of expression
        ASTNode* right;                                 // Right side of expression
};


#endif
