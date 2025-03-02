#include "../include/AST/Expressions/ASTLiteralNode.h"

/* Constructors for int / float variable */
ASTLiteralNode::ASTLiteralNode(LiteralType type, int intValue) :
    ASTNode(NodeType::LITERAL), litType(type) {
        value.intValue = intValue;
    };

ASTLiteralNode::ASTLiteralNode(LiteralType type, float floatValue) :
    ASTNode(NodeType::LITERAL), litType(type) {
        value.floatValue = floatValue;
    };

/* Returns literal type */
ASTLiteralNode::LiteralType ASTLiteralNode::getLiteralType() const {
    return litType;
}

/* Returns the value */
ASTLiteralNode::LiteralValue ASTLiteralNode::getValue() const {
    return value;
}

/* Visitor */
void ASTLiteralNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

