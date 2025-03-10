#ifndef AST_NODE_H
#define AST_NODE_H
#include "../../symbol_table.h"
#include <string>
#include <iostream>
#include <vector>
#include <variant>
#include <utility>
#include <string>
#include <stack>

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

        explicit ASTNode(NodeType type,int line_number);
        NodeType getType() const;
        
        virtual void accept(ASTVisitor& visitor) = 0;

        void setDataType(DataType datatype);
        void setTemp(const std::string& temp);
        
        DataType getDataType() const;
        const std::string& getTemp() const;
        const int getLineNumber() const;

        virtual ~ASTNode();
    private:
        NodeType type;
        std::string temp;
        int line_number;
        DataType dataType;
};


#endif 