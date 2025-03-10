#ifndef AST_H
#define AST_H

/* AST Node Header File */


#include "AST/Base/ASTNode.h"
#include "AST/Base/ASTVisitor.h"

#include "AST/ControlFlow/ASTCaseListNode.h"
#include "AST/ControlFlow/ASTIfNode.h"
#include "AST/ControlFlow/ASTWhileNode.h"
#include "AST/ControlFlow/ASTSwitchNode.h"
#include "AST/ControlFlow/ASTBreakNode.h"

#include "AST/Expressions/ASTBinaryExprNode.h"
#include "AST/Expressions/ASTUnaryExprNode.h"
#include "AST/Expressions/ASTLiteralNode.h"
#include "AST/Expressions/ASTIdentifierNode.h"
#include "AST/Expressions/ASTCastExprNode.h"

#include "AST/Statements/ASTProgramRoot.h"
#include "AST/Statements/ASTAssignNode.h"
#include "AST/Statements/ASTBlockNode.h"
#include "AST/Statements/ASTInputNode.h"
#include "AST/Statements/ASTOutputNode.h"


#endif 
