#ifndef QUAD_GENERATOR_H
#define QUAD_GENERATOR_H

#include "../../AST.h"
#include "../../symbol_table.h"
#include "../../global_scope.h"
#include "QuadInstruction.h"
    

class QuadGenerator : public ASTVisitor {
    public:
        void visit(ASTProgramRoot& node) override;
        void visit(ASTBlockNode& node) override;
        void visit(ASTStatementListNode& node) override;
        void visit(ASTAssignNode& node) override;
        
        void visit(ASTInputNode& node) override;
        void visit(ASTOutputNode& node) override;
        void visit(ASTIfNode& node) override;
        void visit(ASTWhileNode& node) override;
        void visit(ASTCaseListNode& nodes) override;
        void visit(ASTSwitchNode& node) override;
        void visit(ASTBreakNode& node) override;
        void visit(ASTBinaryExprNode& node) override;
        void visit(ASTUnaryExprNode& node) override;
        void visit(ASTCastExprNode& node) override;
        void visit(ASTIdentifierNode& node) override;
        void visit(ASTLiteralNode& node) override;

        void generateQuad(ASTProgramRoot* root);                                                            // The root of the AST leads to the beginning of traversel. (post order)
        void printQuad(std::ostream& out);                                                                                   // We print the commands we parsed   

        void typeConversion(ASTNode* lhsNode, ASTNode* rhsNode);                                            // Converts the operands to floats if needed 
        void performOperation(ASTBinaryExprNode& node, Symbol& lhsSymbol, Symbol& rhsSymbol);               // Performs the correct arethmetic operation and saves result in the node temp          
      
      private:
        std::vector<QuadInstruction> instructions;
        std::vector<std::pair<std::string, int>> casePlaceHolders;                                          // Stores the placeholders for cases in a switch 
        std::string switchTemp;                                                                             // Stores the switch condition
        
};




#endif