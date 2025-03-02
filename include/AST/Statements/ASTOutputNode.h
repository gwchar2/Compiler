#ifndef AST_OUTPUT_NODE_H
#define AST_OUTPUT_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

/*
output_stmt:
    OUTPUT '(' expression ')' ';'
    ;
*/

class ASTOutputNode : public ASTNode {
    public:
        ASTOutputNode(ASTNode* expression);             // Output Constructor
        void accept(ASTVisitor& visitor) override;      // Visitor constructor
        
        ASTNode* getExpression() const;             // Gets the expresion

    private:
        ASTNode* expression;                        // Holds the expression
};


#endif
