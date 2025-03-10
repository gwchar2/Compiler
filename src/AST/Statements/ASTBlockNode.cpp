#include "../include/AST/Statements/ASTBlockNode.h"

/*****************************/
/******** BLOCK NODE *********/
/*****************************/

/* Constructor */
ASTBlockNode::ASTBlockNode(ASTStatementListNode* stmtList)
    : ASTNode(NodeType::BLOCK,-1), statementList(stmtList) {}

/* Visitor */
void ASTBlockNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

/* Retreives the list of statements in the block  */
ASTStatementListNode* ASTBlockNode::getStatementList() const {
    return statementList;
}
