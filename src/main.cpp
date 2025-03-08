#include <iostream>
#include <fstream>
#include <cstdio>
#include "../include/parser.tab.h" 
#include "../include/header.h"
#include "../include/AST/Base/QuadGenerator.h"
#include "../include/AST.h"
#include "../include/symbol_table.h"
#include "../include/global_scope.h"

extern FILE *yyin; 
extern GlobalScope globalScope;
extern int yylineno;
ASTProgramRoot* root = nullptr;
bool errorflag = false;

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
    yyparse();

    // Step 1: Generate TAC
    QuadGenerator quadGen;
    quadGen.generateQuad(root);  
    std::cout <<"\n";
    quadGen.printQuad();

    return 0;
}

