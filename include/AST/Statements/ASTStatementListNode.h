#ifndef AST_STATEMENT_LIST_NODE_H
#define AST_STATEMENT_LIST_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"
#include <vector>

class ASTStatementListNode : public ASTNode {
public:
    ASTStatementListNode();                                     // Constructor
    void accept(ASTVisitor& visitor) override;                 // Visitor 

    void addStatement(ASTNode* stmt);                           // Add a statement to the list
    const std::vector<ASTNode*>& getStatements() const;         // gets the statements list 

private:
    std::vector<ASTNode*> statements;                          // List of statements
};

#endif