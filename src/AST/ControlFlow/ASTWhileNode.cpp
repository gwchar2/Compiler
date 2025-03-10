#include "../include/AST/ControlFlow/ASTWhileNode.h"

/*****************************/
/******** While Node *********/
/*****************************/

/* While Node Constructor */
ASTWhileNode::ASTWhileNode(ASTNode* condition, ASTNode* body,int line_number) :
    ASTNode(NodeType::WHILE_STMT,line_number),condition(condition),body(body) {}

/* Visitor */
void ASTWhileNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

/* Gets the condition node */
ASTNode* ASTWhileNode::getCondition() const {
    return condition;
}

/* Gets the body node */
ASTNode* ASTWhileNode::getBody() const {
    return body;
}
