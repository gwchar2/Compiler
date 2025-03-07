/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_PARSER_TAB_H_INCLUDED
# define YY_YY_BUILD_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

    #include "../include/header.h"
    #include "../include/symbol_table.h"
    #include "../include/parser.tab.h"
    #include "../include/global_scope.h"
    #include "../include/AST.h"
    extern ASTProgramRoot* root;
    extern GlobalScope globalScope;
    extern int yylineno;
    extern int yychar;
    extern char* yytext;
    extern char* unput;
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

#line 76 "build/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BREAK = 258,                   /* BREAK  */
    CASE = 259,                    /* CASE  */
    DEFAULT = 260,                 /* DEFAULT  */
    ELSE = 261,                    /* ELSE  */
    IF = 262,                      /* IF  */
    INPUT = 263,                   /* INPUT  */
    OUTPUT = 264,                  /* OUTPUT  */
    SWITCH = 265,                  /* SWITCH  */
    WHILE = 266,                   /* WHILE  */
    INT = 267,                     /* INT  */
    FLOAT = 268,                   /* FLOAT  */
    NUM = 269,                     /* NUM  */
    ID = 270,                      /* ID  */
    ADDOP = 271,                   /* ADDOP  */
    MULOP = 272,                   /* MULOP  */
    RELOP = 273,                   /* RELOP  */
    CAST = 274,                    /* CAST  */
    ASSIGN = 275,                  /* ASSIGN  */
    OR = 276,                      /* OR  */
    AND = 277,                     /* AND  */
    NOT = 278                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "src/parser.y"
                            // For integers & floats (NUM)
    Val val;
    char* strval;                   // For identifiers (ID) and possibly keywords
    ActionType op;                  // For operators and keywords (symbolic representation)
    DataType dataType;              // For symbol table
    ASTNode* node;                  // ASTNode
    ASTCaseListNode* caseListNode;  // Explicit Case List Node
    ASTStatementListNode* stmtListNode; // Explicit Statement List Node
    ASTProgramRoot* rootNode;               // Root of the AST
    ASTBlockNode* blockNode;


#line 129 "build/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_TAB_H_INCLUDED  */
