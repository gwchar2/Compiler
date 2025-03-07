#include "../include/AST/Expressions/ASTLiteralNode.h"

/* Constructors for int / float variable */
ASTLiteralNode::ASTLiteralNode(int intValue) :
    ASTNode(NodeType::LITERAL){
        value = intValue;
    };

ASTLiteralNode::ASTLiteralNode(float floatValue) :
    ASTNode(NodeType::LITERAL){
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

std::string ASTLiteralNode::getValueAsString() const {
    if (std::holds_alternative<int>(value)) {
        return std::to_string(std::get<int>(value));
    } else {
        return std::to_string(std::get<float>(value));
    }
}

/* Visitor */
void ASTLiteralNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

