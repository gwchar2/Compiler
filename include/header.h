#ifndef HEADER_H  
#define HEADER_H  
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

/* Defines just for cool text color */
#define RESET   "\033[0m"
#define RED     "\033[31m"   
#define YELLOW  "\033[33m"   

/* Error Types - Move to some header? */
enum class ErrorCode{
    ERR_NO_FILE_FOUND,
    ERR_FILE_CANT_BE_OPENED,
    ERR_FILE_CANT_BE_READ,
    ERR_NESTED_COMMENTS,
    ERR_UNTERMINATED_COMMENT,
    ERR_TOKEN_INVALID,
    ERR_NO_SUCH_VARIABLE,
    ERR_MISSING_CONDITION,
    ERR_MISSING_MAIN_CASE,
    ERR_CASE_ISNT_INT,
    ERR_MISSING_CASE_NUMBER,
    ERR_SWITCH_NO_DEFAULT,
    ERR_OP_REQUIRES_TWO,
    ERR_COMPARING_FI,
    ERR_MISSING_EXPRESSION,
    ERR_BREAK_OUTSIDE_WHILE,
    ERR_PARSER,
    ERR_MISSING_INPUT,

};


typedef enum ActionType{
    /* Comparators */
    CMP_LT,                         // less than (<)
    CMP_GT,                         // greater than (>)
    CMP_LTE,                        // less than or equal (<=)
    CMP_GTE,                        // greater than or equal (>=)
    CMP_NE,                         // not equal (!=)
    CMP_EQ,                         // equal (==)

    /* Logical Actions */
    LOGICAL_OR,
    LOGICAL_AND,
    LOGICAL_NOT,

    /* Mathematical Tokens */
    ADD,                            // (+)
    SUB,                            // (-)

    MUL,                            // (*)
    DIV,                            // (/)

    /* Actions */
    ACTION_CASTINT,
    ACTION_CASTFLOAT,
    ACTION_ASSIGN,
    INVALID = -1
} ActionType;

/* Externals */
extern int yylex();   
extern FILE* yyin;                                  // Global file pointer.
extern bool errorFlag;


/* Prints the correct error */
template<typename... Args>
void errorHandler(ErrorCode errorCode,int line, Args... args){
    std::stringstream ss; 

    if (errorCode == ErrorCode::ERR_COMPARING_FI){
        ss << YELLOW << "WARNING" << RESET << " in line " << RED << line << RESET << ": " << " Performing action between int and float (Will be assigned FLOAT automatically).";
        std::cerr << ss.str() << std::endl;
        return;
    }
    
    errorFlag = true;
    
    if (errorCode == ErrorCode::ERR_NO_FILE_FOUND){
        ss << RED << "ERROR" RESET << " missing file name.";
        std::cerr << ss.str() << std::endl;
        return;
    }
    if (errorCode == ErrorCode::ERR_FILE_CANT_BE_OPENED){
        ss << RED << "ERROR" RESET << " could not open the file ";
        ((ss << args << " "), ...);
        std::cerr << ss.str() << std::endl;
        return;
    }
    if (errorCode == ErrorCode::ERR_PARSER){
        ss << RED << "SYNTAX ERROR" RESET << " in line " << RED << line << RESET << ": ";
        ((ss << args << " "), ...);
        std::cerr << ss.str() << std::endl;
        return;
    }

    ss << RED "Error" RESET << " in line " << RED << line << RESET ": ";

    switch (errorCode) {
        case ErrorCode::ERR_NESTED_COMMENTS:
            ss << "Nested comments are not allowed.";
            break;
        case ErrorCode::ERR_UNTERMINATED_COMMENT:
            ss << "Unterminated comment.";
            break;
        case ErrorCode::ERR_TOKEN_INVALID:
            ss << "Token is invalid.";
            break;
        case ErrorCode::ERR_NO_SUCH_VARIABLE:
            ss << "No such variable: ";
            ((ss << args << " "), ...);  
            break;
        case ErrorCode::ERR_MISSING_CONDITION:
            ss << "Statement is missing a condition.";
            break;
        case ErrorCode::ERR_MISSING_MAIN_CASE:
            ss << "Missing main logic.";
            break;
        case ErrorCode::ERR_CASE_ISNT_INT:
            ss << "Case condition must be of INT type.";
            break;
        case ErrorCode::ERR_MISSING_CASE_NUMBER:
            ss << "Missing case condition.";
            break;
        case ErrorCode::ERR_SWITCH_NO_DEFAULT:
            ss << "Switch statement has no default case.";
            break;
        case ErrorCode::ERR_OP_REQUIRES_TWO:
            ss << "Binary operator requires two expressions.";
            break;
        case ErrorCode::ERR_MISSING_EXPRESSION:
            ss << "Statement is missing an expression.";
            break;
        case ErrorCode::ERR_BREAK_OUTSIDE_WHILE:
            ss << "Break statement outside of a while.";
            break;
        default:  
            break;
    }

    std::cerr << ss.str() << std::endl;
}



#endif



