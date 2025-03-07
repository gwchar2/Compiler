#include "../include/AST/ControlFlow/ASTBreakNode.h"


ASTBreakNode::ASTBreakNode() : ASTNode(NodeType::BREAK_STMT), breakAddress(0) {}

void ASTBreakNode::accept(ASTVisitor& visitor) { 
    visitor.visit(*this);
}

void ASTBreakNode::setBreakAddress(int address){
    breakAddress = address;
}

int ASTBreakNode::getBreakAddress(){
    return breakAddress;
}