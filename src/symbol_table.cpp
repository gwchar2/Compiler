// symbol_table.cpp
#include "symbol_table.h"
#include <iostream>
SymbolTable symbolTable;

/* Inserts a new variable to the symbol table */
bool SymbolTable::insert(const std::string& name, DataType type) {
    if (table.find(name) != table.end()) {
        std::cerr << "Error: Variable '" << name << "' is already declared." << std::endl;
        return false;
    }
    /* Create a Symbol */
    Symbol newSymbol;
    newSymbol.name = name;
    newSymbol.typeEnum = type;
    newSymbol.val = (type == DataType::INT) ? std::variant<int, float>(0) : std::variant<int, float>(0.0f);
    
    table[name] = newSymbol;
    return true;
}

/* Checks if a variable exists in the table */
bool SymbolTable::exists(const std::string& name) const {
    return table.find(name) != table.end();
}

/* Returns the symbol if it exists */
Symbol& SymbolTable::getSymbol(const std::string& name) {
    auto it = table.find(name);
    return it -> second;

    // Need to decide if we do catch / throw, or how we handle this error! (if name isnt in symbol table)
    // Allways call exists -> getSymbol
    std::cout << " ERRORRRRRR NEED TO FIX!! " << std::endl;
    
}
void SymbolTable::removeSymbol(const std::string& name){
    table.erase(name);
}

/* Gets the Data Type as a string */
std::string SymbolTable::getTypeStr(const std::string& name) const {
    auto it = table.find(name);
    if (it != table.end()) {
        return it->second.typeStr();
    }
    return "unknown";
}

/* Adds a variabel to the temp list */
void SymbolTable::addTempVariable(const std::string& name) {
    tempVariables.push_back(name);
}

/* Assigns a data type to all the variables in the list */
void SymbolTable::finalizeTempVariables(DataType type) {
    for (const std::string& name : tempVariables) {
        insert(name, type);
    }
    tempVariables.clear(); 
}
