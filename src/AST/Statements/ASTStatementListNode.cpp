#include "../include/AST/Statements/ASTStatementListNode.h"

/* Constructor */
ASTStatementListNode::ASTStatementListNode() : ASTNode(NodeType::STATEMENT_LIST) {}


/* Adds a statement to the vector of statements */
void ASTStatementListNode::addStatement(ASTNode* stmt) {
    statements.push_back(stmt);
}


/* Retreives the statements */
const std::vector<ASTNode*>& ASTStatementListNode::getStatements() const {
    return statements;
}

/* Visitor */
void ASTStatementListNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}
