#ifndef CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_PARSER_H
#define CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_PARSER_H

#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <iostream>
#include <variant>

#include "Enum_operations.h"
#include "BinaryOperations.h"
#include "UnaryOperations.h"

// This function uses "shunting-yard" algorithm to parse expression

std::queue<std::variant<double, OPERATIONS>> Parser(){
    std::map<std::string, OPERATIONS> string_to_OP = {
            {"+", SUM},{"-", SUB},{"/", DIV},
            {"*", MULT},{"^", POWER},{"sin", SIN},
            {"cos", COS},{"tg", TG},{"ctg", CTG},
            {"sqrt", SQRT},{"exp", EXP},{"abs", ABS},
    };

    std::queue<std::variant<double, OPERATIONS>> values;
    std::stack<OPERATIONS> Stack;

    std::string expression;
    getline(std::cin, expression);
    std::istringstream expression_stream(expression);

    double x = 0;
    bool x_is_known = false;

    char c = expression_stream.get();
    bool minus_is_unary = true; // if no number before minus -> it's unary minus

    while (c != EOF) {
        // reading numbers and putting them on stack
        if (isdigit(c) || c == '.') {
            std::string number_string;
            do {
                minus_is_unary = false;
                number_string += c;
            } while ((isdigit(c == expression_stream.get()) || c == '.' ) && c != EOF);

            double number = std::stod(number_string);
            values.push(number);

            if (c == ' ')
                c = expression_stream.get();
        } else {
            // reading operations and putting them on operation stack
            // and if necessary, to main stack
            if (c != '(' && c != ')'){ // if not a bracket
                std::string op_string;
                bool is_not_operator = true;

                do {
                    op_string += c;
                    if (string_to_OP.count(op_string) || op_string == "pi" || op_string == "e" || op_string == "x"){
                        // if we've read an operation from map or constants or user's variable
                        is_not_operator = false;
                    }
                    // reading char by char until we meet a bracket or a number, or already have an operation
                } while (!isdigit(c = expression_stream.get()) && c != '(' && c != ')' && c != EOF && is_not_operator);

                // if we've read something that's not an operation, pi, e, x
                if (op_string != "x" && op_string != "pi" && op_string != "e" && !string_to_OP.count(op_string)){
                    throw std::invalid_argument("Part of an input can't be treated neither as operator "
                                                "nor as constant or variable\nInput: " + op_string);
                }
                // if we've read 'x', push it to values' stack
                // if necessary, ask the value of x
                if (op_string == "x"){
                    if (x_is_known){
                        values.push(x);
                    } else {
                        std::cout << "Enter x:" << std::endl;
                        std::string x_value;
                        getline(std::cin, x_value);
                        x = std::stod(x_value); // may throw std::invalid_argument
                        x_is_known = true;
                        values.push(x);
                    }
                } else if (op_string == "e"){ // if we've read a constant, just push them to values' stack
                    values.push(M_E);
                    minus_is_unary = false;
                } else if (op_string == "pi"){
                    values.push(M_PI);
                    minus_is_unary = false;
                } else {
                    OPERATIONS op = string_to_OP.at(op_string); // finding what operation is it
                    if (op_string == "-" && minus_is_unary){
                        op = U_MINUS;
                    }
                    // moving operations from stack to main queue
                    while (!Stack.empty() && Stack.top() <= op && Stack.top() != OPEN_BRACKET){
                        values.push(Stack.top());
                        Stack.pop();
                    }
                }
            }
        }

    }
}
#endif //CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_PARSER_H
