#ifndef AST_SWITCH_NODE_H
#define AST_SWITCH_NODE_H


#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"
#include "../Statements/ASTStatementListNode.h"
#include "ASTCaseListNode.h"
#include <vector>
#include <utility>

/*
switch_stmt:
    SWITCH '(' expression ')' '{' caselist DEFAULT ':' stmtlist '}'
    ;

caselist:
    caselist CASE INT_LIT ':' stmtlist
    | epsilon
    ;
*/
class ASTSwitchNode : public ASTNode {
    public:
        //Constructor
        ASTSwitchNode(ASTNode* condition, ASTCaseListNode* caseList, ASTStatementListNode* defaultCase);
        
        void accept(ASTVisitor& visitor) override;  // Visitor constructor

        ASTNode* getCondition() const;                                                          // gets the loop condition
        ASTCaseListNode* getCaseList() const;                                                       // case list for switch
        ASTStatementListNode* getDefaultCase() const;                                   // gets default case
        int getBreakAddress() const;                                             // gets the exit address


    private:
        ASTNode* condition;                                                     // Loop condition
        ASTCaseListNode* caseList;           // Case list
        ASTStatementListNode* defaultCase;                                              // Default Case
        int break_address;                                                       // Exit address for break / end of switch

};



#endif
