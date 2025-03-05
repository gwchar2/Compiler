#ifndef AST_BLOCK_NODE_H
#define AST_BLOCK_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"
#include <vector>

/*
stmt_block:
    '{' stmtlist '}'
    ;
*/
class ASTStatementListNode;

class ASTBlockNode : public ASTNode {
    public:
        ASTBlockNode(ASTStatementListNode* stmtList);          // Constructor for class
        void accept(ASTVisitor& visitor) override;              // Visitor Constructor

        ASTStatementListNode* getStatementList() const;  // Gets the statementlist node

    private:
        ASTStatementListNode* statementList;           // Holds the statements in the block    
};



#endif

