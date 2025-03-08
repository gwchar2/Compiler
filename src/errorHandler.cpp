#include "../include/header.h"
extern FILE *yyin;


/* Prints the correct error on lexical analysis phase only */
void errorHandler(ErrorCode errorCode,int line ){
    switch (errorCode){
        /* Normal errors, including the lexer */
        case ErrorCode::ERR_NESTED_COMMENTS:
            std::cerr << "Error in line number: "<< line << " Nested comments are not allowed." << std::endl;
            break;
        case ErrorCode::ERR_UNTERMINATED_COMMENT:
            std::cerr << "Error in line number: "<< line << " Unterminated comment." << std::endl;
            break;
        case ErrorCode::ERR_TOKEN_INVALID:
            std::cerr << "Error in line number: "<< line << " Token is invalid." << std::endl;
            break;
        default:
            break;
    }
}