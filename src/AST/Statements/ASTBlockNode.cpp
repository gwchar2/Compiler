#include "../include/AST/Statements/ASTBlockNode.h"


ASTBlockNode::ASTBlockNode(ASTStatementListNode* stmtList)
    : ASTNode(NodeType::BLOCK), statementList(stmtList) {}

ASTStatementListNode* ASTBlockNode::getStatementList() const {
    return statementList;
}

void ASTBlockNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}