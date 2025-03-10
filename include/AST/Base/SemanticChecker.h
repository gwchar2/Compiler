#ifndef SEMANTIC_CHECKER_H
#define SEMANTIC_CHECKER_H

#include "../../AST.h"
#include "../../global_scope.h"  
#include "../../symbol_table.h" 

class SemanticChecker : public ASTVisitor {

    public:
        void visit(ASTProgramRoot& node) override;
        void visit(ASTBlockNode& node) override;
        void visit(ASTStatementListNode& node) override;
        void visit(ASTInputNode& node) override;
        void visit(ASTOutputNode& node) override;
        void visit(ASTIfNode& node) override;
        void visit(ASTWhileNode& node) override;
        void visit(ASTCaseListNode& node) override;
        void visit(ASTSwitchNode& node) override;
        void visit(ASTBreakNode& node) override;
        void visit(ASTBinaryExprNode& node) override;
        void visit(ASTUnaryExprNode& node) override;
        void visit(ASTCastExprNode& node) override;
        void visit(ASTIdentifierNode& node) override;
        void visit(ASTAssignNode& node) override;
        void visit(ASTLiteralNode& node) override;

        void analyze(ASTProgramRoot* root);

    private:
        bool hasSemanticErrors = false;
        bool inWhile = false;
};

extern SemanticChecker semanticChecker;

#endif
