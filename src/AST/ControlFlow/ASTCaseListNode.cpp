#include "../include/AST/ControlFlow/ASTCaseListNode.h"

/* Constructor */
ASTCaseListNode::ASTCaseListNode()
    : ASTNode(NodeType::CASE_LIST) {}

/* Adds a case to the case list */
void ASTCaseListNode::addCase(ASTLiteralNode* caseValue, ASTStatementListNode* statements) {
    cases.emplace_back(caseValue, statements);
}

/* Returns the list (vector) of cases <num,statementlist>*/
const std::vector<std::pair<ASTLiteralNode*, ASTStatementListNode*>>& ASTCaseListNode::getCases() const {
    return cases;
}

void ASTCaseListNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}
