%{
#include "../include/header.h"
#include "../include/parser.tab.h"

extern FILE *yyin;
int line_number = 1;
int comment_nesting = 0;
%}

/* Macros to define regular expressions */
%option noyywrap 
RELOP     (\<=|\>=|\<|\>|\=\!|\=\=)
ADDOP     (\+|\-)
MULOP     (\*|\/)
OR        (\|\|)
AND       (\&\&)
NOT       (\!)
CAST_INT        (cast<int>)
CAST_FLOAT      (cast<float>)
ID        [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE [ \t\r]+

/* Making a comment rule to handle nested comments */
%x COMMENT 

%%

"/*"               { BEGIN(COMMENT); comment_nesting = 1; }
<COMMENT>{
    "/*"           { 
                        comment_nesting++; /* If we find another comment , comment nesting ++ */
                        if (comment_nesting > 1) {
                            errorHandler(ERR_NESTED_COMMENTS); 
                            BEGIN(INITIAL); 
                        }
                    }  
    "*/"           { 
                        comment_nesting--; 
                        if (comment_nesting == 0) {
                            BEGIN(INITIAL); 
                        }
                    }
    .              { /* Consume any character inside the comment */ }
    <<EOF>>        { 
                        errorHandler(ERR_UNTERMINATED_COMMENT);
                        BEGIN(INITIAL); 
                    }
}
"{"      { 
    return '{'; 
    }
"}"      { 
    return '}'; 
    }
"("      { 
    return '('; 
    }
")"      { 
    return ')'; 
    }
";"      { 
    return ';'; 
    }
":"      { 
    return ':'; 
    }
","      { 
    return ','; 
    }
"="      { 
    yylval.op = ACTION_ASSIGN;
    return ASSIGN; 
    }    
"break"    { 
    return BREAK; 
    }
"case"     { 
    return CASE; 
    }
"default"  { 
    return DEFAULT; 
    }
"else"     { 
    return ELSE; 
    }
"if"       { 
    return IF; 
    }
"input"    { 
    return INPUT; 
    }
"output"   { 
    return OUTPUT; 
    }
"switch"   { 
    return SWITCH; 
    }
"while"    { 
    return WHILE; 
    }
"int"      { 
    return INT; 
    }
"float"    { 
    return FLOAT; 
    }
[0-9]+\.[0-9]+    { 
    yylval.floatval = atof(yytext); return FLOAT_LIT;  
    } 
[0-9]+             { 
    yylval.intval = atoi(yytext); return INT_LIT;
    } 
{RELOP}       {
    yylval.op = get_operator_action(yytext); return RELOP;
    }
{ADDOP}       {
    yylval.op = get_operator_action(yytext); return ADDOP;
    }
{MULOP}       {
    yylval.op = get_operator_action(yytext); return MULOP;
    }
{OR}          {
    yylval.op = LOGICAL_OR; return OR;
    }
{AND}         {
    yylval.op = LOGICAL_AND; return AND;
    }
{NOT}         {
    yylval.op = LOGICAL_NOT; return NOT;
    }
{CAST_INT}        {
    yylval.op = ACTION_CASTINT; return CAST;
    }
{CAST_FLOAT}        {
    yylval.op = ACTION_CASTFLOAT; return CAST;
    }
{ID}          {
    yylval.strval = strdup(yytext); return ID;
    }
{WHITESPACE}  {  }
\n            { 
    yylineno++;
    line_number++; 
    }
.             { 
    errorHandler(ERR_TOKEN_INVALID); 
    }
%%

int yyerror(const char* error_msg) {
    fprintf(stderr, "Syntax error: [%s] \nLine [%d] \nToken [%s]\n", error_msg,yylineno, yytext);
    return 0; 
}

