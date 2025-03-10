%{
#include "../include/header.h"
#include "../include/parser.tab.h"
extern FILE *yyin;
int line_number = 1;
int comment_nesting = 0;
%}
/* Macros to define regular expressions */
%option yylineno
%option noyywrap 
RELOP     (\<=|\>=|\<|\>|\!\=|\=\=)
ADDOP     (\+|\-)
MULOP     (\*|\/)
OR        (\|\|)
AND       (\&\&)
NOT       (\!)
CAST_INT        (cast<int>)
CAST_FLOAT      (cast<float>)
SAVED_REGISTER t[0-9]+
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
                            errorHandler(ErrorCode::ERR_NESTED_COMMENTS,yylineno); 
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
                        errorHandler(ErrorCode::ERR_UNTERMINATED_COMMENT,yylineno);
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
{SAVED_REGISTER} {
    fprintf(stderr, RED "Lexical Error" RESET " in line %d: Invalid variable name %s. tX are saved registers!\n",line_number, yytext);
}
[0-9]+             { 
    yylval.val.val.intval = atoi(yytext); 
    yylval.val.numType = NumType::INT;
    return NUM;
    } 
[0-9]+\.[0-9]+    { 
    yylval.val.val.floatval = atof(yytext); 
    yylval.val.numType = NumType::FLOAT;
    return NUM;  
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

\n          { 
    line_number++;
    }
.           { 
    fprintf(stderr, "Lexical error at line %d: Unrecognized character '%s'\n", yylineno, yytext);
}

%%