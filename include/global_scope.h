#ifndef GLOBAL_SCOPE_H
#define GLOBAL_SCOPE_H

#include <unordered_map>
#include <vector>
#include <stack>
#include <string>
#include <variant>
#include <iostream>
#include <optional>
#include <iomanip>
#include <sstream>

enum class DataType;
class SymbolTable;
struct Symbol;

/* Manages multiple scopes & temporary variables */
class GlobalScope {
    public:
        void pushScope();                                                               // Adds a new scope
        void popScope();                                                                // Removes the current scope
        SymbolTable& currentScope();                                                    // Returns the top scope

        void addDeclaration(const std::string& name);                                   // Adds a un-typed declaration to a temporary list
        void finalizeDeclarations(DataType type);                                       // Inserts all the untyped declarations into the global list with a certain type
        
        Symbol& insert(const std::string& name, DataType type);                         // Adds a variable
        bool exists(const std::string& name) const;                                     // Checks if variable exists
        Symbol& getSymbol(const std::string& name);                                     // Returns a symbol from the scope
        std::string getSymbolByValue(const std::variant<int,float>& val) const;
        
        std::string newTemp(DataType type);                                             // Returns a new temp
        void releaseTemp(const std::string& temp);                                      // Frees a temp from the global scope 

        void printTable();                                                              // Prints the entire scope, not just one

    private:
        std::vector<SymbolTable> scopeStack;                                            // Stack of symbol tables (scopes)
        std::stack<std::string> intTemps;                                               // Global stack of reusable temps
        std::stack<std::string> floatTemps;                                             // Global stack of reusable temps
        std::vector<std::string> tempDeclarations;                                      // Temporary list for global variables (The first Declarations)
        int tempCounter = 0;                                                            // Counter for generating temp variables

};

extern GlobalScope globalScope;                                                         // Gobal Scope



#endif