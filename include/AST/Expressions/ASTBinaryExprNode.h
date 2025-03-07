#ifndef AST_BINARY_EXPR_NODE_H
#define AST_BINARY_EXPR_NODE_H


#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"
#include "../../header.h"
#include "../../symbol_table.h"
class ASTBinaryExprNode : public ASTNode {
    public:
        ASTBinaryExprNode(ActionType op, ASTNode* left, ASTNode* right);  // Constructor
        void accept(ASTVisitor& visitor) override;                      // visitor

        ActionType getOperator() const;                                   // Gets the operator type
        ASTNode* getLeft() const;                                       // Gets the left node in the expression
        ASTNode* getRight() const;                                      // Gets the right node in the expression

    private:
        ActionType op;                                                    // Holds the op
        ASTNode* left;                                                  // Holds left node pointer
        ASTNode* right;                                                 // Holds right node pointer

};



#endif 