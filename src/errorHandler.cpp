#include "../include/header.h"
extern FILE *yyin;


/* Prints the correct error on lexical analysis phase only */
void errorHandler(ErrorCode errorCode){
    switch (errorCode){
        /* Normal errors, including the lexer */
        case 0:
            std::cerr << "Error in line number: "<< line_number << " You must input a file to be read!" << std::endl;
            break;
        case 1:
            std::cerr << "Error in line number: "<< line_number << " The file could not be opened! Make sure it is a readable file." << std::endl;
            break;
        case 2:
            std::cerr << "Error in line number: "<< line_number << " The file could not be opened via yyin(). Make sure it is a readable file." << std::endl;
            break;
        case 3:
            std::cerr << "Error in line number: "<< line_number << " Nested comments are not allowed." << std::endl;
            break;
        case 4:
            std::cerr << "Error in line number: "<< line_number << " Unterminated comment." << std::endl;
            break;
        case 5:
            std::cerr << "Error in line number: "<< line_number << " Token is invalid." << std::endl;
            break;
        default:
            break;
    }
}