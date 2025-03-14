#ifndef AST_CASE_LIST_NODE_H
#define AST_CASE_LIST_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"
class ASTStatementListNode;
class ASTLiteralNode;
/*
caselist:
    caselist CASE INT_LIT ':' stmtlist
    | epsilon
    ;
*/
class ASTCaseListNode : public ASTNode {
    public:
        ASTCaseListNode();                                                                              // Empty node initialization
        void addCase(ASTLiteralNode* caseValue, ASTStatementListNode* statements);                      // Adding a case to the node
        const std::vector<std::pair<ASTLiteralNode*, ASTStatementListNode*>>& getCases() const;         // List of cases

        void accept(ASTVisitor& visitor)  override;
    private:
        std::vector<std::pair<ASTLiteralNode*, ASTStatementListNode*>> cases;                           // List of <Case # , Case >

};



#endif