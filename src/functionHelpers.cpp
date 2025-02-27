#include "../include/header.h"
#include <string>

ActionType get_operator_action(const std::string& op) {
    if (op == "+") return ADD;
    else if (op == "-") return SUB;
    else if (op == "*") return MUL;
    else if (op == "/") return DIV;
    else if (op == "<") return CMP_LT;
    else if (op == ">") return CMP_GT;
    else if (op == "<=") return CMP_LTE;
    else if (op == ">=") return CMP_GTE;
    else if (op == "!=") return CMP_NE;
    else if (op == "==") return CMP_EQ;
    return INVALID;
}
