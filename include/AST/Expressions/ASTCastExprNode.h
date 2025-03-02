#ifndef AST_CAST_EXPR_NODE_H
#define AST_CAST_EXPR_NODE_H


#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

class ASTCastExprNode : public ASTNode {
    public :
        enum class CastType {TO_INT, TO_FLOAT};

        ASTCastExprNode(CastType castType, ASTNode* operand);           // Constructor
        void accept(ASTVisitor& visitor) override;                      // Visitor constructor

        CastType getCastType() const;                                   // Gets the type of cast func
        ASTNode* getOperand() const;                                    // Gets operand

    private:
        CastType castType;                                              // Holds the cast type
        ASTNode* operand;                                               // Holds the operand

};


#endif
