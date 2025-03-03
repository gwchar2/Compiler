#ifndef QUAD_GENERATOR_H
#define QUAD_GENERATOR_H

#include "ASTVisitor.h"
#include "QuadInstruction.h"
#include <vector>
#include <string>

class QuadGenerator : public ASTVisitor {
    public:
        void visit(ASTProgramRoot& node) override;
        void visit(ASTBlockNode& node) override;
        void visit(ASTStatementListNode& node) override;
        void visit(ASTInputNode& node) override;
        void visit(ASTOutputNode& node) override;
        void visit(ASTIfNode& node) override;
        void visit(ASTWhileNode& node) override;
        void visit(ASTSwitchNode& node) override;
        void visit(ASTBreakNode& node) override;
        void visit(ASTCaseListNode& node) override;
        void visit(ASTBinaryExprNode& node) override;
        void visit(ASTUnaryExprNode& node) override;
        void visit(ASTCastExprNode& node) override;
        void visit(ASTIdentifierNode& node) override;
        void visit(ASTAssignNode& node) override;
        void visit(ASTLiteralNode& node) override;

        void generateQuad(ASTProgramRoot* root);                             // The root of the AST leads to the beginning of traversel. (post order)
        void printQuad();                                                    // We print the commands we parsed   

    private:
        std::vector<QuadInstruction> instructions;
        int tempCounter = 0;                                // Counts unique amount of temps in this set of instructions
        int labelCounter = 0;                               // Counts unique labels in this set of instructions

        std::string newTemp();
        std::string newLabel();
};




#endif