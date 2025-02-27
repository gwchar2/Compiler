#include <iostream>
#include <fstream>
#include <cstdio>
#include "../include/parser.tab.h" 
#include "../include/header.h"
extern FILE *yyin; 


/* Helper function to open the file. */
bool openFile(const char* filename) {
    // Try to open the file
    FILE* file = fopen(filename, "r");
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;  
    }
    
    yyin = file;  // Set the input stream for Flex
    return true;   
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error, entered invalid file name:  " << argv[0] << std::endl;
        return 1;  // Return an error if no filename is provided
    }

    const char* filename = argv[1];  // Get the filename from the argument

    // Try to open the file and set yyin for Flex to read from it
    if (!openFile(filename)) {
        return 1;  // Exit with an error code if file opening fails
    }

    // Call yyparse() to run the parser, which in turn calls yylex() from Flex
    int parseResult = yyparse();

    // Check if the parsing was successful
    if (parseResult == 0) {
        std::cout << "Parsing successful!" << std::endl;
    } else {
        std::cerr << "Parsing failed!" << std::endl;
    }

    return 0;
}

