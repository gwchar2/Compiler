%code requires {
    #include "../include/header.h"
    #include "../include/symbol_table.h"
    #include "../include/AST.h"
    extern int yylex(void);  // Ensure this matches your lexer function
    int yyerror(const char *s);

    /* Short struct for NUM values */
    enum class NumType { INT, FLOAT};
    typedef struct {
        NumType numType;            // Type of num
        union {             
            int intval;
            float floatval;
        } val;                      // Holds the value (float or int)
    } Val;
}

%define parse.error verbose
%union {                            // For integers & floats (NUM)
    Val val;
    char* strval;                   // For identifiers (ID) and possibly keywords
    ActionType op;                  // For operators and keywords (symbolic representation)
    DataType dataType;              // For symbol table
    ASTNode* node;                  // ASTNode
    ASTCaseListNode* caseListNode;  // Explicit Case List Node
    ASTStatementListNode* stmtListNode; // Explicit Statement List Node
    ASTProgramRoot* root;               // Root of the AST
    ASTBlockNode* blockNode;

}

%token '{' '}' '(' ')' ';' ':' ',' 
%token BREAK CASE DEFAULT ELSE IF INPUT OUTPUT SWITCH WHILE INT FLOAT
%token <val> NUM 
%token <strval> ID
%token <op> ADDOP MULOP RELOP CAST ASSIGN OR AND NOT
%type <dataType> type
%type <stmtListNode> stmtlist  
%type <caseListNode> caselist
%type <blockNode> stmt_block
%type <root> program
%type <node> boolexpr boolterm boolfactor
%type <node> expression term factor
%type <node> stmt assignment_stmt input_stmt output_stmt 
%type <node> if_stmt while_stmt switch_stmt break_stmt

%%

program:
    declarations stmt_block{
        symbolTable.printTable();
        $$ = new ASTProgramRoot($2);
    }
    ;

declarations:
    declarations declaration
    | /* epsilon */
    ;

declaration:
    idlist ':' type ';'{
        symbolTable.finalizeTempVariables($3);
    }
    ;

type:
    INT{ $$ = DataType::INT; }
    | FLOAT { $$ = DataType::FLOAT; }
    ;

idlist:
    idlist ',' ID{
        symbolTable.addTempVariable($3);                // We add the ID to symbol table temp list
    }
    | ID{
        symbolTable.addTempVariable($1);                // We add the ID to symbol table temp list
    }
    ;

/* Automatically sets $$ = $1 */
stmt:
    assignment_stmt
    | input_stmt
    | output_stmt
    | if_stmt
    | while_stmt
    | switch_stmt
    | break_stmt
    | stmt_block
    ;

assignment_stmt:
    ID ASSIGN expression ';' { $$ = new ASTAssignNode($1,$3);}
    ;

input_stmt:
    INPUT '(' ID ')' ';'{ $$ = new ASTInputNode($3); }
    ;

output_stmt:
    OUTPUT '(' expression ')' ';'{
        $$ = new ASTOutputNode($3);
    }
    ;

if_stmt:
    IF '(' boolexpr ')' stmt ELSE stmt {
        $$ = new ASTIfNode($3,$5,$7);
    }
    ;

while_stmt:
    WHILE '(' boolexpr ')' stmt{
        $$ = new ASTWhileNode($3,$5);
    }
    ;

switch_stmt:
    SWITCH '(' expression ')' '{' caselist DEFAULT ':' stmtlist '}'{
        $$ = new ASTSwitchNode($3,$6,$9);
    }
    ;

/* Need to type check NUM!! ATM can be float ! ILLEGAL! */
caselist:
    caselist CASE NUM ':' stmtlist { 
        $$ = $1;
        $$->addCase(new ASTLiteralNode($3.val.intval), $5);
    }
    | /* epsilon */ { $$ = new ASTCaseListNode(); }
    ;

break_stmt:
    BREAK ';' {$$ = new ASTBreakNode(); }
    ;

stmt_block:
    '{' stmtlist '}' { $$ = new ASTBlockNode($2); }
    ;

stmtlist:
    stmtlist stmt { 
        $$ = $1;
        $$ -> addStatement($2);
    }
    | /* epsilon */ { $$ = new ASTStatementListNode(); }
    ;

boolexpr:
    boolexpr OR boolterm { $$ = new ASTBinaryExprNode($2,$1,$3); }
    | boolterm { $$ = $1; }
    ;

boolterm:
    boolterm AND boolfactor { $$ = new ASTBinaryExprNode($2,$1,$3);}
    | boolfactor {$$ = $1;}
    ;

boolfactor:
    NOT '(' boolexpr ')' { $$ = new ASTUnaryExprNode($3); }
    | expression RELOP expression { $$ = new ASTBinaryExprNode($2,$1,$3); }
    ;

expression:
    expression ADDOP term { $$ = new ASTBinaryExprNode($2,$1,$3); }
    | term { $$ = $1; }
    ;

term:
    term MULOP factor { $$ = new ASTBinaryExprNode($2,$1,$3);}
    | factor { $$ = $1; }
    ;

factor:
    '(' expression ')' { $$ = $2; }
    | CAST '(' expression ')' { $$ = new ASTCastExprNode($1,$3);
     }
    | ID { $$ = new ASTIdentifierNode($1); }
    | NUM { if ($1.numType == NumType::INT) $$ = new ASTLiteralNode($1.val.intval);
            else $$ = new ASTLiteralNode($1.val.floatval); }
    ;

%%