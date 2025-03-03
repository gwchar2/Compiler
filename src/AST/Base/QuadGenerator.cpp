#include "../include/AST/Base/QuadGenerator.h"
#include <iostream>

/* Generates a new temp */
std::string QuadGenerator::newTemp() {
    return "t" + std::to_string(tempCounter++);
}

/* Generates a new label */
std::string QuadGenerator::newLabel() {
    return "L" + std::to_string(labelCounter++);
}

/* Entrance to our visitor traversel class in the AST through Root */
void QuadGenerator::generateQuad(ASTProgramRoot* root){
    root -> accept(*this);
    instructions.emplace_back(QuadOp::HALT);                // We add HALT as the last command
}

/* Prints the Quad instructions */
void QuadGenerator::printQuad() {
    for (const auto& instr : instructions){
        std::cout << instr.toString() << std::endl;
    }
}

/* Visitor method */
void QuadGenerator::visit(ASTProgramRoot& node) {
    node.getStatementBlock() -> accept(*this);
    instructions.emplace_back(QuadOp::HALT);
}