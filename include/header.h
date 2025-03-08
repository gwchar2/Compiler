#ifndef HEADER_H  
#define HEADER_H  
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

/* Error Types - Move to some header? */
enum class ErrorCode{
    ERR_NO_FILE_FOUND,
    ERR_FILE_CANT_BE_OPENED,
    ERR_FILE_CANT_BE_READ,
    ERR_NESTED_COMMENTS,
    ERR_UNTERMINATED_COMMENT,
    ERR_TOKEN_INVALID,
};


typedef enum ActionType{
    /* Comparators */
    CMP_LT,        // less than (<)
    CMP_GT,        // greater than (>)
    CMP_LTE,        // less than or equal (<=)
    CMP_GTE,        // greater than or equal (>=)
    CMP_NE,        // not equal (!=)
    CMP_EQ,        // equal (==)

    /* Logical Actions */
    LOGICAL_OR,
    LOGICAL_AND,
    LOGICAL_NOT,

    /* Mathematical Tokens */
    ADD,           // (+)
    SUB,           // (-)

    MUL,           // (*)
    DIV,           // (/)

    /* Actions */
    ACTION_CASTINT,
    ACTION_CASTFLOAT,
    ACTION_ASSIGN,
    INVALID = -1
} ActionType;

/* errorHandler.c++ */
void errorHandler(ErrorCode errorCode,int line);             // Error text function

/* helper_funcs.cpp */
ActionType get_operator_action(const std::string&op);     // Returns the correct Action Type

/* Externals */
extern int yylex();   
extern FILE* yyin;                                  // Global file pointer.
extern bool errorFlag;




#endif



