#ifndef AST_BREAK_NODE_H
#define AST_BREAK_NODE_H

#include "../Base/ASTNode.h"
#include "../Base/ASTVisitor.h"

/* 
break_stmt:
    BREAK ';'
    ;
*/
class ASTBreakNode : public ASTNode {
public:
    ASTBreakNode();                             // Empty constructor, break node is just a symbolic node
    void accept(ASTVisitor& visitor) override;      // visitor
};

#endif 