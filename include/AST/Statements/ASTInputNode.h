#ifndef AST_INPUT_NODE_H
#define AST_INPUT_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

/*

input_stmt:
    INPUT '(' ID ')' ';'
    ;
*/

class ASTInputNode : public ASTNode {

    public:
        ASTInputNode(const std::string& id,int line);                   // Constructor
        void accept(ASTVisitor& visitor) override;                      // Visitor constructor

        const std::string& getID() const;                               // Gets the ID

    private:
        std::string id;                                                 // Holds the ID
};




#endif
