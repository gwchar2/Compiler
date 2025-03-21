#ifndef AST_SWITCH_NODE_H
#define AST_SWITCH_NODE_H


#include "../Base/ASTNode.h"
#include "../Statements/ASTStatementListNode.h"

/*
switch_stmt:
    SWITCH '(' expression ')' '{' caselist DEFAULT ':' stmtlist '}'
    ;

caselist:
    caselist CASE INT_LIT ':' stmtlist
    | epsilon
    ;
*/
// No idea why the heck this wont work -> #include "ASTCaseListNode.h" but whatever...Lets just use class
class ASTCaseListNode;

class ASTSwitchNode : public ASTNode {
    public:
        //Constructor
        ASTSwitchNode(ASTNode* condition, ASTCaseListNode* caseList, ASTStatementListNode* defaultCase,int line);       // Constructor 
        
        void accept(ASTVisitor& visitor) override;                                                                      // Visitor

        ASTNode* getCondition() const;                                                                                  // gets the loop condition
        ASTCaseListNode* getCaseList() const;                                                                           // case list for switch
        ASTStatementListNode* getDefaultCase() const;                                                                   // gets default case


    private:
        ASTNode* condition;                                                                                             // Loop condition
        ASTCaseListNode* caseList;                                                                                      // Case list
        ASTStatementListNode* defaultCase;                                                                              // Default Case
        int break_address;                                                                                              // Exit address for break / end of switch

};



#endif
