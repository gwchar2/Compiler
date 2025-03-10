#ifndef AST_LITERAL_NODE_H
#define AST_LITERAL_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

/* Represents a Literal Node */
class ASTLiteralNode : public ASTNode {
    public:
        ASTLiteralNode(int value,int line);                                     // Int Constructor
        ASTLiteralNode(float value,int line);                                   // Float Constructor
        void accept(ASTVisitor& visitor) override;                              // Visitor 

        std::variant<int, float> getValue() const;                              // Returns the value of the node 
        std::string getValueAsString() const;                                   // Returns value as a string 
        bool isInt() const;                                                     // Bools for returning class type quickly
        bool isFloat() const;                                                   // Bools for returning class type quickly
    
    private:
        std::variant<int, float> value;                                         // Holds the value of the literal
        DataType type;

};


#endif