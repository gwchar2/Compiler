#include "../include/AST/ControlFlow/ASTSwitchNode.h"

/******************************/
/******** Switch Node *********/
/******************************/

/* Constructor */
ASTSwitchNode::ASTSwitchNode(ASTNode* condition, ASTCaseListNode* caseList, ASTStatementListNode* defaultCase,int line_number) : 
    ASTNode(NodeType::SWITCH_STMT, line_number), condition(condition), caseList(caseList), defaultCase(defaultCase), break_address(-1){}

/* Visitor */
void ASTSwitchNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

/* Returns the condition node */
ASTNode* ASTSwitchNode::getCondition() const {
    return condition;
}

/* Returns the case list node */
ASTCaseListNode* ASTSwitchNode::getCaseList() const {
    return caseList;
}

/* Returns the default case node */
ASTStatementListNode*  ASTSwitchNode::getDefaultCase() const {
    return defaultCase;
}
