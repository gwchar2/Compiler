#ifndef AST_IDENTIFIER_NODE_H
#define AST_IDENTIFIER_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

/* ID Node Type Class*/
class ASTIdentifierNode : public ASTNode {
    public:
        ASTIdentifierNode(const std::string& name,int line);                    // Constructor
        void accept(ASTVisitor& visitor) override;                              // Visitor class
        
        const std::string& getName() const;                                     // Gets the name of ID
        bool isCasted();                                                        // Indicater if this identifier has been casted 
        void setCasted(bool status);                                            // Sets casting status 
    private:
        std::string name;                                                       // Holds the ID Name
        std::string castedName;
        bool casted;

};

#endif 