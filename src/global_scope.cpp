#include "../include/global_scope.h"
#include "../include/symbol_table.h"
GlobalScope globalScope;


/* Adds a scope to the stack */
void GlobalScope::pushScope() {
    scopeStack.emplace_back();
}

/* Pops a scope from the stack */
void GlobalScope::popScope() {
    if (scopeStack.size() > 1){
        /* We get the last stack & remove its temporaries */
        SymbolTable& last = scopeStack.back();
        last.releaseTemporaries();

        /* Pop the scope */
        scopeStack.pop_back();
    }
}

/* Returns the current scope */
SymbolTable& GlobalScope::currentScope() {
    if (!scopeStack.empty()) return scopeStack.back();
    throw std::runtime_error("GlobalScope::currentScope() : No active scope available!");
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
const Symbol& GlobalScope::getSymbol(const std::string& name) const {
    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); it++) {
        if (it->exists(name)) {
            return it->getSymbol(name);  
        }
    }
    throw std::runtime_error("Symbol not found: " + name);
}

/* Returns the first symbol with the same value in the scope */
std::optional<std::string> GlobalScope::getSymbolByValue(const std::variant<int, float>& val) const {
    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); it++) {
        for (auto& [key, symbol] : it->getSymbols()) { 
            if (symbol.getVal() == val)
                return key; 
        }
    }
    return std::nullopt;  
}

/* Creates a new temp */
std::string GlobalScope::newTemp(){
    if (freeTemps.empty())  return "t"+std::to_string(tempCounter++);
    std::string temp = freeTemps.top();
    freeTemps.pop();
    return temp;
}

/* Releases a temp from current scope and adds it to the free temps stack */
void GlobalScope::releaseTemp(const std::string& temp){
    currentScope().removeSymbol(temp);
    freeTemps.push(temp);
}

void GlobalScope::printTable(){
    std::cout << "\n === Symbol Tables in Global Scope ===\n";
    for (size_t i = 0 ; i < scopeStack.size(); i ++) {
        std::cout << "Scope " << i << ":\n";
        scopeStack[i].printTable();
    }
}
