#ifndef CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_UNARYOPERATIONS_H
#define CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_UNARYOPERATIONS_H

#include "UnaryOperation.h"
#include <cmath>

class UnaryMinusOperation final : public UnaryOperation {
    double apply(double value) const override {
        return -value;
    }
public:
    UnaryMinusOperation(const std::shared_ptr<Operation> operand) : UnaryOperation(operand) {}
};

class SinusOperation final : public UnaryOperation {
    double apply(double value) const override {
        return sin(value);
    }
public:
    SinusOperation(const std::shared_ptr<Operation> operand) : UnaryOperation(operand) {}
};

class CosinusOperation final : public UnaryOperation {
    double apply(double value) const override {
        return cos(value);
    }
public:
    CosinusOperation(const std::shared_ptr<Operation> operand) : UnaryOperation(operand) {}
};

class TangentOperation final : public UnaryOperation {
    double apply(double value) const override {
        return tan(value);
    }
public:
    TangentOperation(const std::shared_ptr<Operation> operand) : UnaryOperation(operand) {}
};

class CotangentOperation final : public UnaryOperation {
    double apply(double value) const override {
        return 1/tan(value);
    }
public:
    CotangentOperation(const std::shared_ptr<Operation> operand) : UnaryOperation(operand) {}
};

class ExponentOperation final : public UnaryOperation {
    double apply(double value) const override {
        return exp(value);
    }
public:
    ExponentOperation(const std::shared_ptr<Operation> operand) : UnaryOperation(operand) {}
};

class SquareRootOperation final : public UnaryOperation {
    double apply(double value) const override {
        return sqrt(value);
    }
public:
    SquareRootOperation(const std::shared_ptr<Operation> operand) : UnaryOperation(operand) {}
};

class AbsOperation final : public UnaryOperation {
    double apply(double value) const override {
        return fabs(value);
    }
public:
    AbsOperation(const std::shared_ptr<Operation> operand) : UnaryOperation(operand) {}
};

class ConstantOperation final : public Operation {
    double value;
public:
    double result() const override {
        return value;
    }
public:
    explicit ConstantOperation(double value) : value(value) {}
};




#endif //CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_UNARYOPERATIONS_H
