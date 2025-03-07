#ifndef AST_NODE_H
#define AST_NODE_H
#include <string>
#include <iostream>

class ASTVisitor;

/* Main AST Node class. 
Holds Type of Node, Virtual Destructor, and an 'accept' class that must be implemented by visitors
*/
class ASTNode {
    public:
        enum class NodeType {
            ROOT, LITERAL, IDENTIFIER, BINARY_EXPR, UNARY_EXPR, CAST_EXPR,
            ASSIGNMENT, INPUT, OUTPUT, IF_STMT, WHILE_STMT, SWITCH_STMT, BREAK_STMT, BLOCK, STATEMENT_LIST,CASE_LIST
        };

        explicit ASTNode(NodeType type);
        NodeType getType() const;
        
        virtual void accept(ASTVisitor& visitor) = 0;
        virtual ~ASTNode();

        void setTemp(const std::string& temp);
        const std::string& getTemp() const;
    private:
        NodeType type;
        std::string temp;
};


#endif 