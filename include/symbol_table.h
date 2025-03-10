#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "global_scope.h"


/* Data types of variables */
enum class DataType { INT, FLOAT, UNKNOWN };

/* The symbol / token stored in the symbol table */
struct Symbol {
    std::string name;                                                       // Name of symbol
    DataType typeEnum;                                                      // Type of symbol
    std::variant<int, float> val;                                           // Holds value (int/float)

    /* Gets the type of the symbol */
    DataType getType() const { return typeEnum; }
    
    /* Sets the data type of symbol */
    void setType(DataType type) { typeEnum = type; }

    /* Gets the symbol value */
    std::variant<int, float> getVal() const { return val; }

    /* Sets a new value */
    void setVal(std::variant<int, float> newVal) { val = newVal; }

    /* Converts value to string */
    std::string valStr() const {
        std::ostringstream stream;
        if (std::holds_alternative<int>(val))
            stream << std::get<int>(val);
        else 
            stream << std::fixed << std::setprecision(3) << std::get<float>(val);
        
        return stream.str();
    }

    /* Returns symbol name */
    std::string getName() const {
        return name;
    }

    /* Sets symbol name */
    void setName(std::string newName) {
        name = newName;
    }
    
    /* Converts type to a readable string (Mostly debugging) */
    std::string typeStr() const {                                          
        switch (typeEnum) {
            case DataType::INT: return "int";
            case DataType::FLOAT: return "float";
            default: return "unknown";
        }
    }
};

/* Represents a single scope */
class SymbolTable {
    public:
        Symbol& insert(const std::string& name, DataType type);                 // Adds a variable to the table
        bool exists(const std::string& name) const;                             // Checks if a variable exists
        Symbol& getSymbol(const std::string& name);                             // Retrieves a symbol
        const std::unordered_map<std::string, Symbol>& getSymbols() const;      // Retreives the scope
        std::vector<std::string> getTemporaries() const;                        // Retrieves the temoporaries that are in use
         
        void removeSymbol(const std::string& name);                             // Removes a variable
        void addTemporary(const std::string& temp, DataType type);              // Tracks temp variables
        void releaseTemporaries();                                              // Releases all temporaries in this scope
        void printTable();                                                      // Prints the current scope 

    private:
        std::unordered_map<std::string, Symbol> symbols;                        // Symbols in the scope
        std::vector<std::string> temporaries;                                   // Tracks temporaries in this scope

};
extern GlobalScope globalScope;
#endif
