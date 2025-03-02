#ifndef AST_BINARY_EXPR_NODE_H
#define AST_BINARY_EXPR_NODE_H


#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

class ASTBinaryExprNode : public ASTNode {
    public:
        enum class BinaryOp { ADD, SUB, MUL, DIV, CMP_LT, CMP_GT, CMP_LTE, CMP_GTE, CMP_NE, CMP_EQ, AND, OR }; // Type of Node

        ASTBinaryExprNode(BinaryOp op, ASTNode* left, ASTNode* right);  // Constructor
        void accept(ASTVisitor& visitor) override;                      // visitor

        BinaryOp getOperator() const;                                   // Gets the operator type
        ASTNode* getLeft() const;                                       // Gets the left node in the expression
        ASTNode* getRight() const;                                      // Gets the right node in the expression

    private:
        BinaryOp op;                                                    // Holds the op
        ASTNode* left;                                                  // Holds left node pointer
        ASTNode* right;                                                 // Holds right node pointer

};



#endif 