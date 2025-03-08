#ifndef AST_ASSIGN_NODE_H
#define AST_ASSIGN_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"


class ASTAssignNode : public ASTNode {
    public:
        ASTAssignNode(const std::string& id, ASTNode* expression);  // Constructor
        void accept(ASTVisitor& visitor) override;                  // Visitor func constructor

        const std::string& getID() const;                           // Get left side
        ASTNode* getExpression() const;                             // Get right side

    private:
        std::string id;                                            // Left side of expression
        ASTNode* expression;                                             // Right side of expression
};


#endif
