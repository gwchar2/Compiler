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
        ASTInputNode(ASTNode* identifier);                 // Constructor
        void accept(ASTVisitor& visitor) override;      // Visitor constructor

        ASTNode* getIdentifier() const;             // Gets the ID

    private:
        ASTNode* identifier;                        // Holds the ID
};




#endif
