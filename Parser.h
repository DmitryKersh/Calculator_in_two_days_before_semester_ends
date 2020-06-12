#ifndef CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_PARSER_H
#define CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_PARSER_H

#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <iostream>

#include "Enum_operations.h"
#include "BinaryOperations.h"
#include "UnaryOperations.h"

std::queue<OPERATIONS> Parser(){
    std::map<std::string, OPERATIONS> string_to_OP = {
            {"+", SUM},{"-", SUB},{"/", DIV},
            {"*", MULT},{"^", POWER},{"sin", SIN},
            {"cos", COS},{"tg", TG},{"ctg", CTG},
            {"sqrt", SQRT},{"exp", EXP},{"abs", ABS},
    };

    std::queue<OPERATIONS> values;
    std::stack<OPERATIONS> Stack;

    std::string expression;
    getline(std::cin, expression);
    std::istringstream expression_stream(expression);

    double x = 0;
    bool x_is_known = false;

    int c = expression_stream.get();
    bool minus_is_unary;

    while (c != EOF) {

    }
}
#endif //CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_PARSER_H
