// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>


/* Data types of variables */
enum class DataType { INT, FLOAT, UNKNOWN };

/* The symbol / token inputted into the symbol table */
struct Symbol {
    std::string name;                       // Name of symbol
    DataType typeEnum;                      // Type of symbol
    std::string typeStr() const {           // Returns string representation for debugging
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
    DataType getType(const std::string& name) const;                        // Gets the type of symbol
    std::string getTypeStr(const std::string& name) const;                  // Gets the type of symbol as a string
    void addTempVariable(const std::string& name);                          // Adds a variable to the temporary list
    void finalizeTempVariables(DataType type);                              // Adds a data type to the list of temporary variables
    void printTable() const {                                               // Print for debugging
        std::cout << "Symbol Table:\n";
        for (const auto& entry : table) {
            std::cout << "  " << entry.second.name << " : " << entry.second.typeStr() << "\n";
        }
    }
};

extern SymbolTable symbolTable;                                             // Initiate the symbol table globaly

#endif 