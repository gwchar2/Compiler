#include "../include/AST/Expressions/ASTLiteralNode.h"

/*****************************/
/******* Literal Node ********/
/*****************************/

/* Visitor */
void ASTLiteralNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

/* Constructors for int / float variable */
ASTLiteralNode::ASTLiteralNode(int intValue,int line_number) :
    ASTNode(NodeType::LITERAL,line_number){
        value = intValue;
    };

ASTLiteralNode::ASTLiteralNode(float floatValue,int line_number) :
    ASTNode(NodeType::LITERAL,line_number){
        value = floatValue;
    };

/* Returns the value */
std::variant<int, float> ASTLiteralNode::getValue() const {
    return value;
}

/* Type returners */
bool ASTLiteralNode::isInt() const {
    return std::holds_alternative<int>(value);
}

bool ASTLiteralNode::isFloat() const {
    return std::holds_alternative<float>(value);
}

/* Returns the value, but as a string with up to .000 */
std::string ASTLiteralNode::getValueAsString() const {
    std::ostringstream oss;
        if (std::holds_alternative<int>(value))
            oss << std::get<int>(value);
        else 
            oss << std::fixed << std::setprecision(3) << std::get<float>(value);
        
        return oss.str();
}



