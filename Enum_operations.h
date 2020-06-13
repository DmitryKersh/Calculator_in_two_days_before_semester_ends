#ifndef CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_ENUM_OPERATIONS_H
#define CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_ENUM_OPERATIONS_H

enum OPERATIONS {

    // unary
    // values are priorities of operations. The more 10's in value, the higher priority
    // i.e 22 and 29 are same priority, but 31 is higher than 29
    SIN = 1,
    COS = 2,
    TG = 3,
    CTG = 4,
    ABS = 5,
    EXP = 6,
    SQRT = 7,
    U_MINUS = 31,

    // binary
    POWER = 41,
    MULT = 22,
    DIV = 21,
    SUM = 11,
    SUB = 12,

    // brackets
    // these priorities don't matter because brackets are handled separately from operations
    OPEN_BRACKET = 1000,
    CLOSE_BRACKET = 1001
};

[[nodiscard]] int get_priority(const OPERATIONS& op) { return op / 10; }

#endif //CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_ENUM_OPERATIONS_H
