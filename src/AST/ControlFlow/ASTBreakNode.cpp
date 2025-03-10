#include "../include/AST/ControlFlow/ASTBreakNode.h"

/*****************************/
/******** BREAK NODE *********/
/*****************************/

/* Constructor */
ASTBreakNode::ASTBreakNode(int line_number) : ASTNode(NodeType::BREAK_STMT, line_number){}

/* Visitor */
void ASTBreakNode::accept(ASTVisitor& visitor) { 
    visitor.visit(*this);
}
