#include "../include/header.h"
using namespace std;
extern FILE *yyin;


/* Prints the correct error on lexical analysis phase only */
void errorHandler(ErrorCode errorCode){
    switch (errorCode){
        /* Normal errors, including the lexer */
        case 0:
            cerr << "Error in line number: "<< line_number << " You must input a file to be read!" << endl;
            break;
        case 1:
            cerr << "Error in line number: "<< line_number << " The file could not be opened! Make sure it is a readable file." << endl;
            break;
        case 2:
            cerr << "Error in line number: "<< line_number << " The file could not be opened via yyin(). Make sure it is a readable file." << endl;
            break;
        case 3:
            cerr << "Error in line number: "<< line_number << " Nested comments are not allowed." << endl;
            break;
        case 4:
            cerr << "Error in line number: "<< line_number << " Unterminated comment." << endl;
            break;
        case 5:
            cerr << "Error in line number: "<< line_number << " Token is invalid." << endl;
            break;
        default:
            break;
    }
}