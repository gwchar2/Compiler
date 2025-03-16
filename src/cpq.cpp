#include "../include/parser.tab.h" 
#include "../include/header.h"
#include "../include/AST/Base/QuadGenerator.h"
#include "../include/AST.h"
#include "../include/symbol_table.h"
#include "../include/global_scope.h"
#include "../include/AST/Base/SemanticChecker.h"
#include <cstdio>

/* External and global flags */
extern FILE *yyin; 
extern GlobalScope globalScope;
ASTProgramRoot* root = nullptr;
bool errorFlag = false;


/* Main logic for the program. */
int main(int argc, char* argv[]) {
    
    /* Checks entered file name */
    if (argc < 2) {
        errorHandler(ErrorCode::ERR_NO_FILE_FOUND,0);
        return 1;  
    }
    
    /* Gets file name & adds .ou */
    std::string filename = argv[1];  
    std::string newFileName = filename;
    /* If the file name does not end with .ou , we add it. If it does, we dont.
        -- This is mainly for Make tests command on makefile -- */
    if (filename.size() >= 3 && !(filename.substr(filename.size() - 3) == ".ou")) 
        newFileName = filename+".ou";

    /* Opens the file, yyin needs FILE* :( */
    FILE* file = fopen(newFileName.c_str(), "r");
    if (!file){
        errorHandler(ErrorCode::ERR_FILE_CANT_BE_OPENED,0,newFileName);
        return 1;
    }

    /* Sets yyin with the file */
    yyin = file;

    /* שורת "חותמת" עם שם הסטודנט */
    std::cout << "Student Name: Tommer Toledo 209706795" << std::endl;

    /* Step 1: Calls the parser */
    yyparse();

    /* Step 2: Semantic Analasys */
    SemanticChecker semanticCheck;
    semanticCheck.analyze(root);

    /* Step 3: If no errors, we make the output */
    if (!errorFlag){
        /* Generate the code */
        QuadGenerator quadGen;
        quadGen.generateQuad(root); 

        /* Set output file to filename.qud ( Again, the checks are mainly for make tests command in makefile )*/
        if (filename.size() < 3 || filename.substr(filename.size() - 3) != ".ou") {
            newFileName = filename + ".qud";
        } else {
            newFileName = filename.substr(0, filename.size() - 3) + ".qud";
        }
        
        /* Set the stream & call for print */
        std::ofstream outFile(newFileName);
        if (outFile)
            quadGen.printQuad(outFile);
        else errorHandler(ErrorCode::ERR_FILE_CANT_BE_OPENED,0,newFileName);
        
        //globalScope.printTable();
    }


    return 0;
}

