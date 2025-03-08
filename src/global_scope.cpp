#include "../include/global_scope.h"
#include "../include/symbol_table.h"
GlobalScope globalScope;


/* Adds a scope to the stack */
void GlobalScope::pushScope() {
    scopeStack.emplace_back();
}

/* Pops a scope from the stack */
void GlobalScope::popScope() {
    if (!scopeStack.empty()) {
        /* Release temporaries from the current scope */
        scopeStack.back().releaseTemporaries();

        /* Pop the last scope */
        scopeStack.pop_back();
    } 
}

/* Returns the current scope */
SymbolTable& GlobalScope::currentScope() {
    if (scopeStack.empty()) scopeStack.emplace_back();
    return scopeStack.back();
}

/* We add a typeless declaration to the temporary declarations list */
void GlobalScope::addDeclaration(const std::string& name) {
    tempDeclarations.push_back(name);
}

/* We add the declarations to the global scope, with a specific type */
void GlobalScope::finalizeDeclarations(DataType type){
    if (scopeStack.empty()) pushScope();
    for (const std::string& name : tempDeclarations){
        scopeStack[0].insert(name,type);
    }
    tempDeclarations.clear();
}

/* Inserts to the current scope and returns a pointer to it */
Symbol& GlobalScope::insert(const std::string& name, DataType type) {
    return currentScope().insert(name, type);  
}

/* Checks if a variable exists in the stack at all */
bool GlobalScope::exists(const std::string& name) const {
    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); it ++ ){
        if (it -> exists(name)) return true;
    }
    return false;
}

/* Returns the first symbol with the specific name */
Symbol& GlobalScope::getSymbol(const std::string& name) {
    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); it++) {
        if (it->exists(name)) {
            return it->getSymbol(name);  
        }
    }
    throw std::runtime_error("Symbol not found: " + name);
}

/* Returns the first symbol with the same value in the scope */
std::string GlobalScope::getSymbolByValue(const std::variant<int, float>& val) const {
    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); it++) {
        for (const auto& [key, symbol] : it -> getSymbols()) { 
            /* Makes sure it compares same type. searching for '5' wont return a val of '5.0' */
            if (symbol.getVal().index() == val.index() && symbol.getVal() == val)
                return key; 
        }
    }
    return "";  
}

/* Creates a new temp */
std::string GlobalScope::newTemp(DataType type){
    if (type == DataType::INT) {
        if (!intTemps.empty()) {
            std::string temp = intTemps.top();
            intTemps.pop();
            globalScope.insert(temp,type);
            return temp;
        }
    } else {
        if (!floatTemps.empty()) {
            std::string temp = floatTemps.top();
            floatTemps.pop();
            globalScope.insert(temp,type);
            return temp;
        }
    }

    std::string tempname = "t" + std::to_string(tempCounter++);
    globalScope.currentScope().addTemporary(tempname,type);
    return tempname;
}

/* Releases a temp from current scope and adds it to the free temps stack */
void GlobalScope::releaseTemp(const std::string& temp){
    if (globalScope.exists(temp)) {
        if (globalScope.getSymbol(temp).getType() == DataType::INT) 
            intTemps.push(temp);
        else 
            floatTemps.push(temp);
        globalScope.currentScope().removeSymbol(temp);
    }
}

void GlobalScope::printTable(){
    std::cout << "\n === Symbol Tables in Global Scope ===\n";
    for (size_t i = 0 ; i < scopeStack.size(); i ++) {
        std::cout << "Scope " << i << ":" <<std::endl;
        scopeStack[i].printTable();
    }
}
