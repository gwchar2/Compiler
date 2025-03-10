%code requires {
    #include "../include/header.h"
    #include "../include/symbol_table.h"
    #include "../include/parser.tab.h"
    #include "../include/global_scope.h"
    #include "../include/AST.h"
    extern ASTProgramRoot* root;
    extern GlobalScope globalScope;
    extern int line_number;
    extern int yychar;
    extern char* yytext;
    #define yyerrok         (yyerrstatus = 0)
    extern int yylex(void);  // Ensure this matches your lexer function
    void yyerror(const char *s);

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
    ASTProgramRoot* rootNode;               // Root of the AST
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
%type <node> stmt_block
%type <rootNode> program
%type <node> boolexpr boolterm boolfactor
%type <node> expression term factor
%type <node> stmt assignment_stmt input_stmt output_stmt 
%type <node> if_stmt while_stmt switch_stmt break_stmt

%%

program:
    declarations stmt_block {
        //globalScope.printTable();
        root = new ASTProgramRoot($2);
    }
    

declarations:
    declarations declaration
    | declarations error { yyerrok; yyclearin; }
    | /* epsilon */
    ;

declaration:
    idlist ':' type ';' {
        globalScope.finalizeDeclarations($3);
    }
    | error ':' type ';' { yyerrok; yyclearin; }
    | idlist ':' error ';' { yyerrok; yyclearin; }
    | error ':' error ';' { yyerrok; yyclearin; }
    ;

type:
    INT{ $$ = DataType::INT; }
    | FLOAT { $$ = DataType::FLOAT; }
    ;

idlist:
    idlist ',' ID{
        globalScope.addDeclaration($3);                // We add the ID to symbol table temp list
    }
    | ID{
        globalScope.addDeclaration($1);                // We add the ID to symbol table temp list
    }
    | idlist error ID { yyerrok; yyclearin; }
    | idlist ',' error { yyerrok; yyclearin; }
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

assignment_stmt:
    ID ASSIGN expression ';' { 
        $$ = new ASTAssignNode($1,$3,line_number);}
    | ID '=' error ';' { yyerrok; yyclearin; $$ = nullptr; }
    ;

input_stmt:
    INPUT '(' ID ')' ';' { $$ = new ASTInputNode($3,line_number); }
    | INPUT '(' error ')' ';' { yyerrok; yyclearin; $$ = nullptr; }
    ;

output_stmt:
    OUTPUT '(' expression ')' ';' {
        $$ = new ASTOutputNode($3,line_number);
    }
    | OUTPUT '(' error ')' ';' { yyerrok; yyclearin; $$ = nullptr; }
    ;

if_stmt:
    IF '(' boolexpr ')' stmt ELSE stmt {
        $$ = new ASTIfNode($3,$5,$7,line_number);
    }
    | IF '(' error ')' stmt ELSE stmt { yyerrok; yyclearin; $$ = nullptr; }
    ;

while_stmt:
    WHILE '(' boolexpr ')' stmt{
        $$ = new ASTWhileNode($3,$5,line_number);
    }
    | WHILE '(' error ')' stmt { yyerrok; yyclearin; $$ = nullptr; }
    ;

switch_stmt:
    SWITCH '(' expression ')' '{' caselist DEFAULT ':' stmtlist '}'{
        $$ = new ASTSwitchNode($3,$6,$9,line_number);
    }
    | SWITCH '(' error ')' '{' caselist DEFAULT ':' stmtlist '}' { yyerrok; yyclearin; $$ = nullptr; }
    ;

/* Need to type check NUM!! ATM can be float ! ILLEGAL! */
caselist:
    caselist CASE NUM ':' stmtlist { 
        $$ = $1;
        $$->addCase(new ASTLiteralNode($3.val.intval,line_number), $5);
    }
    | error CASE NUM ':' stmtlist { yyerrok; yyclearin; $$ = nullptr; }
    | /* epsilon */ { $$ = new ASTCaseListNode(); }
    ;

break_stmt:
    BREAK ';'  {$$ = new ASTBreakNode(line_number); }
    ;

stmt_block:
    '{' stmtlist '}'  { $$ = new ASTBlockNode($2); }
    | '{' error '}' { yyerrok; yyclearin; $$ = nullptr; }
    ;

stmtlist:
    stmtlist stmt  { 
        $$ = $1;
        $$ -> addStatement($2);
    }
    | /* epsilon */ { $$ = new ASTStatementListNode(); }
    ;

boolexpr:
    boolexpr OR boolterm { $$ = new ASTBinaryExprNode($2,$1,$3,line_number); }
    | boolterm { $$ = $1; }
    | error OR boolterm { yyerrok; yyclearin; $$ = nullptr; }
    | boolexpr OR error { yyerrok; yyclearin; $$ = nullptr; }
    | error OR error { yyerrok; yyclearin; $$ = nullptr; }
    ;

boolterm:
    boolterm AND boolfactor { $$ = new ASTBinaryExprNode($2,$1,$3,line_number);}
    | boolfactor {$$ = $1;}
    | error AND boolfactor { yyerrok; yyclearin; $$ = nullptr; }
    | boolterm AND error { yyerrok; yyclearin; $$ = nullptr; }
    | error AND error { yyerrok; yyclearin; $$ = nullptr; }
    ;

boolfactor:
    NOT '(' boolexpr ')' { $$ = new ASTUnaryExprNode($3,line_number); }
    | expression RELOP expression { $$ = new ASTBinaryExprNode($2,$1,$3,line_number); }
    | NOT '(' error ')' { yyerrok; yyclearin; $$ = nullptr; }
    | error RELOP expression { yyerrok; yyclearin; $$ = nullptr; }
    | expression RELOP error { yyerrok; yyclearin; $$ = nullptr; }
    | error RELOP error { yyerrok; yyclearin; $$ = nullptr; }
    ;

expression:
    expression ADDOP term { $$ = new ASTBinaryExprNode($2,$1,$3,line_number); }
    | term { $$ = $1; }
    | expression ADDOP error { yyerrok; yyclearin; $$ = nullptr; }
    | error ADDOP term { yyerrok; yyclearin; $$ = nullptr; }
    | error ADDOP error { yyerrok; yyclearin; $$ = nullptr; }
    ;

term:
    term MULOP factor { $$ = new ASTBinaryExprNode($2,$1,$3,line_number);}
    | factor { $$ = $1; }
    | error MULOP factor { yyerrok; yyclearin; $$ = nullptr; }
    | term MULOP error { yyerrok; yyclearin; $$ = nullptr; }
    | error MULOP error { yyerrok; yyclearin; $$ = nullptr; }
    ;

factor:
    '(' expression ')' { $$ = $2; }
    | CAST '(' expression ')' { $$ = new ASTCastExprNode($1,$3,line_number);}
    | ID { $$ = new ASTIdentifierNode($1,line_number); }
    | NUM { 
        if ($1.numType == NumType::INT) $$ = new ASTLiteralNode($1.val.intval,line_number);
        else $$ = new ASTLiteralNode($1.val.floatval,line_number); 
            }
    | '(' error ')' { yyerrok; yyclearin; $$ = nullptr; }
    | CAST '(' error ')' { yyerrok; yyclearin; $$ = nullptr; }
    ;


%%

void yyerror(const char* error_msg) {
    errorHandler(ErrorCode::ERR_PARSER,line_number,error_msg);
    if (yychar == YYEOF)  return;
}
