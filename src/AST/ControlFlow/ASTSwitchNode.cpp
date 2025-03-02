#include "../include/AST/ControlFlow/ASTSwitchNode.h"

/* Constructor */
ASTSwitchNode::ASTSwitchNode(ASTNode* condition, ASTCaseListNode* caseList, ASTStatementListNode* defaultCase, int break_address) : 
    ASTNode(NodeType::SWITCH_STMT), condition(condition), caseList(caseList), defaultCase(defaultCase), break_address(-1){}

void ASTSwitchNode::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

ASTNode* ASTSwitchNode::getCondition() const {
    return condition;
}

ASTCaseListNode* ASTSwitchNode::getCaseList() const {
    return caseList;
}

ASTStatementListNode*  ASTSwitchNode::getDefaultCase() const {
    return defaultCase;
}

int ASTSwitchNode::getBreakAddress() const {
    return break_address;
}