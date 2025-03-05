#ifndef AST_CAST_EXPR_NODE_H
#define AST_CAST_EXPR_NODE_H


#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"
#include "../../header.h"

class ASTCastExprNode : public ASTNode {
    public :

        ASTCastExprNode(ActionType castType, ASTNode* operand);           // Constructor
        void accept(ASTVisitor& visitor) override;                      // Visitor constructor

        ActionType getCastType() const;                                   // Gets the type of cast func
        ASTNode* getOperand() const;                                    // Gets operand
        void setTemp(const std::string& temp);
    private:
        ActionType castType;                                              // Holds the cast type
        ASTNode* operand;                                               // Holds the operand
        std::string temp;
};


#endif
