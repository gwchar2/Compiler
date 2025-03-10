#ifndef AST_IF_NODE_H
#define AST_IF_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

/*
if_stmt:
    IF '(' boolexpr ')' stmt ELSE stmt
    ;
*/

class ASTIfNode : public ASTNode {
    public:
    // Constructors
        ASTIfNode(ASTNode* condition, ASTNode* mainBlock, ASTNode* elseBlock,int line_number);
        void accept(ASTVisitor& visitor) override;

        ASTNode* getCondition() const;                              // gets loop condition
        ASTNode* getMainBlock() const;                              // gets Main Block
        ASTNode* getElseBlock() const;                              // gets the else block

    private:
        ASTNode* condition;                                         // Loop Condition
        ASTNode* mainBlock;                                         // Main-Block
        ASTNode* elseBlock;                                         // Else-block
};





#endif
