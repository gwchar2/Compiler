#include "../include/AST/ControlFlow/ASTBreakNode.h"


ASTBreakNode::ASTBreakNode() : ASTNode(NodeType::BREAK_STMT) {}

void ASTBreakNode::accept(ASTVisitor& visitor) { 
    visitor.visit(*this);
}