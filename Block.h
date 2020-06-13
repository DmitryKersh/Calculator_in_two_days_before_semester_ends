#ifndef CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_BLOCK_H
#define CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_BLOCK_H

#include "Enum_operations.h"
#include <cmath>
#include <exception>
#include <stdexcept>


class UnaryBlock {
    double arg;
    double res;
    OPERATIONS op;

public:
    UnaryBlock(const double& value, OPERATIONS operation) : arg(value), op(operation) {
        if (operation == U_MINUS){
            res = -value;
        }
        if (operation == SIN){
            res = sin(value);
        }
        if (operation == COS){
            res = cos(value);
        }
        if (operation == TG){
            res = tan(value);
        }
        if (operation == CTG){
            res = 1/tan(value);
        }
        if (operation == EXP){
            res = exp(value);
        }
        if (operation == ABS){
            res = fabs(value);
        }
        if (operation == SQRT){
            res = sqrt(value);
        }
    }
    [[nodiscard]] double result() const { return res; }
};

class BinaryBlock {
    double lhs;
    double rhs;
    OPERATIONS op;
    double res;
public:
    BinaryBlock(const double& lhs, const double& rhs, OPERATIONS operation) : lhs(lhs), rhs(rhs), op(operation){
        if (operation == SUM){
            res = lhs + rhs;
        }
        if (operation == SUB){
            res = lhs - rhs;
        }
        if (operation == MULT){
            res = lhs * rhs;
        }
        if (operation == DIV){
            if (rhs == 0) throw std::invalid_argument("Division by zero");
            res = lhs / rhs;
        }
        if (operation == POWER){
            res = pow(lhs, rhs);
        }
    }
    [[nodiscard]] double result() const { return res; }
};


#endif //CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_BLOCK_H
