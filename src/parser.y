%code requires {
    #include "../include/header.h"
    #include "../include/symbol_table.h"
    extern int yylex(void);  // Ensure this matches your lexer function
    int yyerror(const char *s);
}

%define parse.error verbose
%union {
    int intval;        // For integers (NUM)
    double floatval;   // For floating-point numbers (NUM)
    char* strval;      // For identifiers (ID) and possibly keywords
    ActionType op;     // For operators and keywords (symbolic representation)
    DataType dataType;
}

%token '{' '}' '(' ')' ';' ':' ',' 
%token BREAK CASE DEFAULT ELSE IF INPUT OUTPUT SWITCH WHILE OR AND NOT INT FLOAT
%token <intval> INT_LIT
%token <floatval> FLOAT_LIT;   
%token <strval> ID
%token <op> ADDOP MULOP RELOP CAST ASSIGN
%type <dataType> type
%%

program:
    declarations stmt_block{
        symbolTable.printTable();
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

stmt_block:
    '{' stmtlist '}'
    ;

stmtlist:
    stmtlist stmt
    | /* epsilon */
    ;

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
    ID ASSIGN expression ';' 
    ;

input_stmt:
    INPUT '(' ID ')' ';'
    ;

output_stmt:
    OUTPUT '(' expression ')' ';'
    ;

if_stmt:
    IF '(' boolexpr ')' stmt ELSE stmt
    ;

while_stmt:
    WHILE '(' boolexpr ')' stmt
    ;

switch_stmt:
    SWITCH '(' expression ')' '{' caselist DEFAULT ':' stmtlist '}'
    ;

caselist:
    caselist CASE INT_LIT ':' stmtlist
    | /* epsilon */
    ;

break_stmt:
    BREAK ';'
    ;

boolexpr:
    boolexpr OR boolterm
    | boolterm
    ;

boolterm:
    boolterm AND boolfactor
    | boolfactor
    ;

boolfactor:
    NOT '(' boolexpr ')'
    | expression RELOP expression
    ;

expression:
    expression ADDOP term
    | term
    ;

term:
    term MULOP factor
    | factor
    ;

factor:
    '(' expression ')'
    | CAST '(' expression ')'
    | ID 
    | INT_LIT
    | FLOAT_LIT
    ;

%%