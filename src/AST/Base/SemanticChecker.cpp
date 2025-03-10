#include "../include/AST/Base/SemanticChecker.h"
#include "../include/header.h"

extern GlobalScope globalScope;

/*****************************/
/***** Semantic Analysis *****/
/*****************************/


/* Launches the semantic analysis. */
void SemanticChecker::analyze(ASTProgramRoot* root){
    root -> accept(*this);
}

/* Checks Root Node */
void SemanticChecker::visit(ASTProgramRoot& node){
    if (node.getMainBlock()) node.getMainBlock() -> accept(*this);
}

/* Checks the block node (statement list) */
void SemanticChecker::visit(ASTBlockNode& node){
    if (node.getStatementList()) node.getStatementList() -> accept(*this);
}

/* Checks statement list node */
void SemanticChecker::visit(ASTStatementListNode& node){
    for (ASTNode* stmt : node.getStatements()){
        if (stmt){
            stmt -> accept(*this);
        }
    }
}

/* Checks input node */
void SemanticChecker::visit(ASTInputNode& node){
    /* We check that the variable is predefined */
    if (!globalScope.exists(node.getID())){
        errorHandler(ErrorCode::ERR_NO_SUCH_VARIABLE,node.getLineNumber(),node.getID());
    }
}

/* Checks output node */
void SemanticChecker::visit(ASTOutputNode& node){
    /* Checks that the expression is valid and exists. */
    if (node.getExpression()) node.getExpression() -> accept(*this);
    else errorHandler(ErrorCode::ERR_MISSING_EXPRESSION,node.getLineNumber());
}

/* Checks if/else nodes */
void SemanticChecker::visit(ASTIfNode& node){
    /* Checks the condition is valid */
    if (node.getCondition()) node.getCondition() -> accept(*this);
    else errorHandler(ErrorCode::ERR_MISSING_CONDITION,node.getLineNumber());

    /* Checks for main block */
    if (node.getMainBlock()) node.getMainBlock() -> accept(*this);
    else errorHandler(ErrorCode::ERR_MISSING_MAIN_CASE, node.getLineNumber());

    /* Checks for else block - it can be empty! stmt -> stmt_block -> stmtlist -> epsilon */
    if (node.getElseBlock()) node.getElseBlock() -> accept(*this);
}

/* Checks while node */
void SemanticChecker::visit(ASTWhileNode& node){
    /* Mark we are in while loop, mostly for break statement */
    inWhile = true;
    /* Check the condition */
    if (node.getCondition()) node.getCondition() -> accept(*this);
    else errorHandler(ErrorCode::ERR_MISSING_CONDITION,node.getLineNumber());
    
    /* Check the main body of loop */
    if (node.getBody()) node.getBody() -> accept(*this);
    else errorHandler(ErrorCode::ERR_MISSING_MAIN_CASE, node.getLineNumber());
    
    /* Mark we are leaving the while */
    inWhile = false;
}

/* Checks case list node */
void SemanticChecker::visit(ASTCaseListNode& node){
    /* For every case, we check that case # is INT and statements are ok. statements can be epsilon. */
    for (auto& pair : node.getCases()){
        if (pair.first){
            if (pair.first->getDataType() != DataType::INT) errorHandler(ErrorCode::ERR_CASE_ISNT_INT,node.getLineNumber());
        } else errorHandler(ErrorCode::ERR_MISSING_CASE_NUMBER,node.getLineNumber());
        if (pair.second) pair.second -> accept(*this);
        // No need for else, empty cases are legal in the grammar.
        // stmtlist -> epsilon
    }
}

/* Checks switch node */
void SemanticChecker::visit(ASTSwitchNode& node){
    /* Checks the condition */
    if (node.getCondition())    node.getCondition() -> accept(*this);
    else errorHandler(ErrorCode::ERR_MISSING_CONDITION,node.getLineNumber());

    /* Checks the cases, cases can be empty, caselist -> epsilon */
    if (node.getCaseList())     node.getCaseList() -> accept(*this);

    /* Must have default case. */
    if (node.getDefaultCase())  node.getDefaultCase() -> accept(*this);
    else errorHandler(ErrorCode::ERR_SWITCH_NO_DEFAULT,node.getLineNumber());
}

/* Checks break node */
void SemanticChecker::visit(ASTBreakNode& node){
    /* If we aren't in a while, illegal to have a break. */
    if (!inWhile)   errorHandler(ErrorCode::ERR_BREAK_OUTSIDE_WHILE,node.getLineNumber());
}

/* Checks binary expr node */
void SemanticChecker::visit(ASTBinaryExprNode& node){
    /* Automatic type conversion if comparing or doing actions on different types.
        Type conversion is performed by QuadGenerator::typeConversion() function. */
    if (node.getLeft()){
        node.getLeft() -> accept(*this);
        node.setDataType(node.getLeft() -> getDataType());
    } else errorHandler(ErrorCode::ERR_OP_REQUIRES_TWO,node.getLineNumber());
    if (node.getRight()){
        node.getRight() -> accept(*this);
        node.setDataType(node.getRight() -> getDataType());
    } else errorHandler(ErrorCode::ERR_OP_REQUIRES_TWO,node.getLineNumber());
    
    
    if (node.getLeft() && node.getRight()){
        /* If we are doing a binary operation it is always an int */
        if (node.getOperator() < 8)
            node.setDataType(DataType::INT);
            /* If it is anything else, it will be float if both are different. Int otherwise. */
        else if (node.getLeft() ->getDataType() != node.getRight() -> getDataType()){
            node.setDataType(DataType::FLOAT);
            errorHandler(ErrorCode::ERR_COMPARING_FI,node.getLineNumber());
        }

    /* If they arent different, than they are the same, and we already set them to be one of them in first if cases */
    }

}

/* Checks unary expr node */
void SemanticChecker::visit(ASTUnaryExprNode& node){
    /* Checks the operand in the unary expression. */
    if (node.getOperand())      node.getOperand() -> accept(*this);
    else errorHandler(ErrorCode::ERR_MISSING_EXPRESSION,node.getLineNumber());
    
    /* Type is always an int */
    node.setDataType(DataType::INT);
}

/* Checks cast node */
void SemanticChecker::visit(ASTCastExprNode& node){
    /* Checks the operand of the cast, and sets data type of this node to the cast type */
    if (node.getOperand()) {
        node.getOperand() -> accept(*this);
        node.setDataType(node.getCastType() == ActionType::ACTION_CASTFLOAT ? DataType::FLOAT : DataType::INT);
    } else 
        errorHandler(ErrorCode::ERR_MISSING_CONDITION,node.getLineNumber());
}

/* Checks assign nodes */
void SemanticChecker::visit(ASTAssignNode& node){
    /* Checks for a legal expression */
    if (node.getExpression())   node.getExpression() -> accept(*this);
    else {
        errorHandler(ErrorCode::ERR_MISSING_CONDITION,node.getLineNumber());
        return;
    }
    /* If the ID we are assigning to, wasn't predefined, we return an error */
    if (!globalScope.exists(node.getID()))  errorHandler(ErrorCode::ERR_NO_SUCH_VARIABLE,node.getLineNumber(),node.getID());
    
    /* We set the node type. If the node type is mixed, we return warning.
        Warning because it will be fixed automatically! */
    node.setDataType(globalScope.getSymbol(node.getID()).getType());
    if (node.getExpression() -> getDataType() != node.getDataType())
        errorHandler(ErrorCode::ERR_COMPARING_FI,node.getLineNumber());
}

/* Checks identifier nodes */
void SemanticChecker::visit(ASTIdentifierNode& node){
    /* If the node ID is not defined, we return error */
    if (!globalScope.exists(node.getName())) {
        errorHandler(ErrorCode::ERR_NO_SUCH_VARIABLE,node.getLineNumber(),node.getName());
        return;
    }

    /* We set the node data type as the type of variable we have */
    node.setDataType(globalScope.getSymbol(node.getName()).getType());
}

/* Checks literal nodes */
void SemanticChecker::visit(ASTLiteralNode& node){
    /* We set the data type as the type of the number */
    node.setDataType(node.isFloat() ? DataType::FLOAT : DataType::INT);
}