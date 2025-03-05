// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <variant>

/* Data types of variables */
enum class DataType { INT, FLOAT, UNKNOWN };

/* The symbol / token inputted into the symbol table */
struct Symbol {
    std::string name;                                                       // Name of symbol
    DataType typeEnum;                                                      // Type of symbol
    std::variant<int,float> val;

    /* Gets the type of value that is stored */
    DataType getType() const {
        return typeEnum;
    }

    /* Returns the value of the symbol */
    std::variant<int,float> getVal() const{
        return val;
    }

    /* Sets a float value */
    void setVal(std::variant<int, float> newVal){
        val = newVal;
    }

    /* Returns string representation for debugging */
    std::string typeStr() const {                                          
        switch (typeEnum) {
            case DataType::INT: return "int";
            case DataType::FLOAT: return "float";
            default: return "unknown";
        }
    }
};

/* Symbol Table Class*/
class SymbolTable {
private:
    std::unordered_map<std::string, Symbol> table;                          // Holds the Symbol Table
    std::vector<std::string> tempVariables;                                 // A vector holding a temporary list of variables until we reach : float or : int

public:
    
    bool insert(const std::string& name, DataType type);                    // Inserts a new variable to the symbol table
    bool exists(const std::string& name) const;                             // Checks if a variable already exists
    Symbol& getSymbol(const std::string& name);                 // Returns a specific symbol from the table 
    std::string getTypeStr(const std::string& name) const;                  // Gets the type of symbol as a string (for debugging mostly)
    void addTempVariable(const std::string& name);                          // Adds a variable to the temporary list
    void finalizeTempVariables(DataType type);                              // Adds a data type to the list of temporary variables
    void removeSymbol(const std::string& name);                             // Removes a symbol from the table, mostly a temporary
    /* Debug printing, if it is still here than I probably forgot to delete it or was lazy */
    void printTable() const {                                               
        std::cout << "Symbol Table:\n";
        for (const auto& entry : table) {
            std::cout << "  " << entry.second.name << " : " << entry.second.typeStr() << " : ";
            std::visit([](auto&& value) { std::cout << value; }, entry.second.getVal());

            std::cout << std::endl;
        }
    }
};

extern SymbolTable symbolTable;                                             // Initiate the symbol table globaly

#endif 