#include "../include/header.h"
#include <string>

ActionType get_operator_action(const std::string& op) {
    if (op == "+") return ActionType::ADD;
    else if (op == "-") return ActionType::SUB;
    else if (op == "*") return ActionType::MUL;
    else if (op == "/") return ActionType::DIV;
    else if (op == "<") return ActionType::CMP_LT;
    else if (op == ">") return ActionType::CMP_GT;
    else if (op == "<=") return ActionType::CMP_LTE;
    else if (op == ">=") return ActionType::CMP_GTE;
    else if (op == "!=") return ActionType::CMP_NE;
    else if (op == "==") return ActionType::CMP_EQ;
    return ActionType::INVALID;
}