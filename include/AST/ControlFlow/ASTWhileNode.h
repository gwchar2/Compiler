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
        ASTWhileNode(ASTNode* condition, ASTNode* body,int cond_address, int body_address,int return_address);    // Constructor with a condition and a body of statements
        void accept(ASTVisitor& visitor) override;

        ASTNode* getCondition() const;                        // Get the condition node
        ASTNode* getBody() const;                             // Get the body node
        int getCondAddress() const;
        int getBodyAddress() const;
        int getReturnAddress() const;
    private:
        ASTNode* condition;                             // Loop condition
        ASTNode* body;                                  // Loop body
        int cond_address;        
        int body_address;
        int return_address;                             // return address for a break

};



#endif
