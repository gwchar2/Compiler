#ifndef AST_VISITOR_H
#define AST_VISITOR_H

#include "../../AST.h"

class ASTVisitor {                          

public:
    virtual void visit(class ASTProgramRoot& node) = 0;             // Root of the AST
    virtual void visit(class ASTBlockNode& node) = 0;
    virtual void visit(class ASTStatementListNode& node) = 0;
    virtual void visit(class ASTInputNode& node) = 0;
    virtual void visit(class ASTOutputNode& node) = 0;
    virtual void visit(class ASTIfNode& node) = 0;
    virtual void visit(class ASTWhileNode& node) = 0;
    virtual void visit(class ASTCaseListNode& node) = 0;
    virtual void visit(class ASTSwitchNode& node) = 0;
    virtual void visit(class ASTBreakNode& node) = 0;
    virtual void visit(class ASTBinaryExprNode& node) = 0;
    virtual void visit(class ASTUnaryExprNode& node) = 0;
    virtual void visit(class ASTCastExprNode& node) = 0;
    virtual void visit(class ASTIdentifierNode& node) = 0;
    virtual void visit(class ASTAssignNode& node) = 0;
    virtual void visit(class ASTLiteralNode& node) = 0;         
    virtual ~ASTVisitor() = default;                                // Virtual destructor, public for inheritance!
};


#endif
