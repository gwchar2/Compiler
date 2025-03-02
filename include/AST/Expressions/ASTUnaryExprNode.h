#ifndef AST_UNARY_EXPR_NODE_H
#define AST_UNARY_EXPR_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"


class ASTUnaryExprNode : public ASTNode {
    public:
        enum class UnaryOp { NOT };     // Negative number or NOT symbol

        ASTUnaryExprNode(UnaryOp op, ASTNode* operand);     // Constructor
        void accept(ASTVisitor& visitor) override;      // Visitor constructor

        UnaryOp getOperator() const;                // Gets the type of node
        ASTNode* getOperand() const;                 // Gets the operand 

    private:
        UnaryOp op;                                 // Holds the type of node
        ASTNode* operand;                           // Holds the function
    
};



#endif
