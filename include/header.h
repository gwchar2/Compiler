#ifndef HEADER_H  
#define HEADER_H  
#include <iostream>
#include <fstream>
#include <string>
#include <variant>
#include <iomanip>

/* Error Types */
typedef enum ErrorCode{
    ERR_NO_FILE_FOUND,
    ERR_FILE_CANT_BE_OPENED,
    ERR_FILE_CANT_BE_READ,
    ERR_NESTED_COMMENTS,
    ERR_UNTERMINATED_COMMENT,
    ERR_TOKEN_INVALID,
    ERR_OUTPUT_FILE
} ErrorCode; 

typedef enum ActionType{
    /* Comparators */
    CMP_LT,        // less than (<)
    CMP_GT,        // greater than (>)
    CMP_LTE,        // less than or equal (<=)
    CMP_GTE,        // greater than or equal (>=)
    CMP_NE,        // not equal (!=)
    CMP_EQ,        // equal (==)

    /* Mathematical Tokens */
    ADD,           // (+)
    SUB,           // (-)

    MUL,           // (*)
    DIV,           // (/)

    /* Logical Actions */
    LOGICAL_OR,
    LOGICAL_AND,
    LOGICAL_NOT,

    /* Actions */
    ACTION_CASTINT,
    ACTION_CASTFLOAT,
    ACTION_ASSIGN,
    INVALID = -1
} ActionType;

/* errorHandler.c++ */
void errorHandler(ErrorCode errorCode);             // Error text function

/* functions.cpp */
ActionType get_operator_action(const std::string&op);     // Returns the correct Action Type

/* Externals */
extern int yylex();   
extern class Token currentToken;                    // Global Token class.
extern FILE* yyin;                                  // Global file pointer.
extern int line_number;                             // Global line number. 
#endif