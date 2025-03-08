// symbol_table.cpp
#include "../include/symbol_table.h"
#include "../include/global_scope.h"

/*******************/
/*  Symbol Tables  */
/*******************/
/* Inserts a new variable into the symbol table and returns a pointer to it */
Symbol& SymbolTable::insert(const std::string& name, DataType type){
    Symbol newSymbol;
    newSymbol.name = name;
    newSymbol.typeEnum = type;
    newSymbol.val = (type == DataType::INT)
                    ? std::variant<int, float>(std::in_place_type<int>, 0)
                    : std::variant<int, float>(std::in_place_type<float>, 0.0f);
    symbols[name] = newSymbol;
    return symbols[name];
}

/* Checks if a variable already exists */
bool SymbolTable::exists(const std::string& name) const{
    return symbols.find(name) != symbols.end();
}

/* Retrieves a symbol from the table. If it doesn't exist, returns nullptr. */
Symbol& SymbolTable::getSymbol(const std::string& name) {
    auto it = symbols.find(name);
    if (it == symbols.end()) {
        throw std::runtime_error("Error: Variable '" + name + "' not found in the symbol table.");
    }
    return it->second;  // Return const reference
}

/* Returns the symbols in the symbol table */
const std::unordered_map<std::string,Symbol>& SymbolTable::getSymbols() const {
    return symbols;
}

/* Removes  symbol from the table */
void SymbolTable::removeSymbol(const std::string& name) {
    symbols.erase(name);
}

/* Adds a temporary variable to this scope */
/* Adds it to the symboltable as well, the removal / free is done through the global scope
    when a scope is popped. */
void SymbolTable::addTemporary(const std::string& temp, DataType type){
    temporaries.push_back(temp);
    insert(temp,type);
}

std::vector<std::string> SymbolTable::getTemporaries() const{
    return temporaries;
}

/* We release the temporaries in this scope*/
void SymbolTable::releaseTemporaries(){
    for (const std::string& temp : temporaries) {
        globalScope.releaseTemp(temp);
        symbols.erase(temp);
    }
    temporaries.clear();
}

void SymbolTable::printTable(){
    for (const auto& entry : symbols)
        std::cout << " " << entry.first << " : " << entry.second.valStr() << " : " << entry.second.typeStr()<<std::endl;
}