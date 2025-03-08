#ifndef AST_WHILE_NODE_H
#define AST_WHILE_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

/*
while_stmt:
    WHILE '(' boolexpr ')' stmt
    ;
*/

class ASTWhileNode : public ASTNode{
    public:
        ASTWhileNode(ASTNode* condition, ASTNode* body);    // Constructor with a condition and a body of statements
        void accept(ASTVisitor& visitor) override;

        ASTNode* getCondition() const;                        // Get the condition node
        ASTNode* getBody() const;                             // Get the body node

    private:
        ASTNode* condition;                             // Loop condition
        ASTNode* body;                                  // Loop body

};



#endif
