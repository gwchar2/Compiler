#ifndef AST_LITERAL_NODE_H
#define AST_LITERAL_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

/* Represents a Literal Node */
class ASTLiteralNode : public ASTNode {
    public:
        enum class LiteralType { INT, FLOAT };                  // Literal Type
        typedef union {                                         // Literal value typedef
            int intValue;
            float floatValue;
        } LiteralValue; 

        ASTLiteralNode(LiteralType litType, int value);         // Constructor1
        ASTLiteralNode(LiteralType litType, float value);       // Constructor2
        void accept(ASTVisitor& visitor) override;

        LiteralType getLiteralType() const;                     // Gets the type of the Literal
        LiteralValue getValue() const;                                 // Gets the value of the Literal

    private:
        LiteralType litType;                                    // Holds the type of literal (Int or float)
        LiteralValue value;                                     // Holds the value of the literal
};


#endif