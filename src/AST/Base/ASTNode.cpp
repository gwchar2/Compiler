#include "../include/AST/Base/ASTNode.h"

/* Constructor */
ASTNode::ASTNode(NodeType type,int line_number) : type(type), line_number(line_number){}

/* Get type func */
ASTNode::NodeType ASTNode::getType() const {
    return type;
}

/* Sets the temporary value to be used for holding a result */
void ASTNode::setTemp(const std::string& temp) {
    this -> temp = temp;
}

/* Gets the name of the temp holding the nodes data */
const std::string& ASTNode::getTemp() const {
    return temp;
}

/* Get the line number it appears in our code */
const int ASTNode::getLineNumber() const {
    return line_number;
}

/* Returns the data type this node will hold in the future */
DataType ASTNode::getDataType() const {
    return dataType;
}

/* Sets the type of data this node holds in the future */
void ASTNode::setDataType(DataType datatype) {
    dataType = datatype;
}

/* Destructor */
ASTNode::~ASTNode() {}