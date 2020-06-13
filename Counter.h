#ifndef CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_COUNTER_H
#define CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_COUNTER_H

#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <iostream>
#include <variant>

#include "Enum_operations.h"
#include "Block.h"

bool is_unary (const OPERATIONS& op){
    return
    op == U_MINUS ||
    op == SQRT ||
    op == SIN ||
    op == COS ||
    op == TG ||
    op == CTG ||
    op == ABS ||
    op == EXP;
}

double count_expression (std::queue<std::variant<double, OPERATIONS>>& values){
    std::stack<double> result;

    // for conditions when expression has no numbers or operations
    bool has_numbers = false;
    bool has_operations = false;
    size_t queuesize = values.size();

    while (!values.empty()){
        if (values.front().index() == 0){ // if double
            has_numbers = true;
            result.push(std::get<double>(values.front()));
        } else {
            //if (!has_numbers) throw std::logic_error("Expression has no numbers");

            has_operations = true;
            if (!is_unary(std::get<OPERATIONS>(values.front()))){ // if binary operation
                if (result.size() < 2) throw std::logic_error("Few arguments for binary operation");

                //taking arguments for binary operation
                double rhs = result.top(); result.pop();
                double lhs = result.top(); result.pop();
                BinaryBlock block(lhs, rhs, std::get<OPERATIONS>(values.front()));
                result.push(block.result());
            } else { // if unary operation
                if (result.empty()) throw std::logic_error("No arguments for unary operation");

                //taking argument
                double value = result.top(); result.pop();
                UnaryBlock block(value, std::get<OPERATIONS>(values.front()));
                result.push(block.result());
            }
        }
        values.pop();
    }

    //if (!has_operations && queuesize > 1) throw std::logic_error("Expression has ho operations");

    return result.top();
}

#endif //CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_COUNTER_H
