#ifndef AST_UNARY_EXPR_NODE_H
#define AST_UNARY_EXPR_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"
#include "../../header.h"


class ASTUnaryExprNode : public ASTNode {
    public:
        ASTUnaryExprNode(ASTNode* operand);     // Constructor
        void accept(ASTVisitor& visitor) override;      // Visitor constructor

        ASTNode* getOperand() const;                 // Gets the operand 

    private:
        ASTNode* operand;                           // Holds the function
    
};



#endif
