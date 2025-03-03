#ifndef AST_LITERAL_NODE_H
#define AST_LITERAL_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"
#include <variant>

/* Represents a Literal Node */
class ASTLiteralNode : public ASTNode {
    public:
        ASTLiteralNode(int value);         // Constructor1
        ASTLiteralNode(float value);        // Constructor2
        void accept(ASTVisitor& visitor) override;

        std::variant<int, float> getValue() const;
        bool isInt() const;
        bool isFloat() const;
    private:
        std::variant<int, float> value;                                     // Holds the value of the literal

};


#endif