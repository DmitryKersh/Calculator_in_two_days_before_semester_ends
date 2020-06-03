#ifndef CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_BINARYOPERATIONS_H
#define CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_BINARYOPERATIONS_H
#include "BinaryOperation.h"
#include <cmath>

class PlusOperation final : public BinaryOperation {
    double apply(double left, double right) const override{
        return left + right;
    }
public:
    PlusOperation(const std::shared_ptr<Operation> left, const std::shared_ptr<Operation> right)
            : BinaryOperation(left, right) {}

};

class MinusOperation final : public BinaryOperation {
    double apply(double left, double right) const override{
        return left - right;
    }
public:
    MinusOperation(const std::shared_ptr<Operation> left, const std::shared_ptr<Operation> right)
            : BinaryOperation(left, right) {}

};

class MultOperation final : public BinaryOperation {
    double apply(double left, double right) const override{
        return left * right;
    }
public:
    MultOperation(const std::shared_ptr<Operation> left, const std::shared_ptr<Operation> right)
            : BinaryOperation(left, right) {}

};

class DivOperation final : public BinaryOperation {
    double apply(double left, double right) const override{
        return left / right;
    }
public:
    DivOperation(const std::shared_ptr<Operation> left, const std::shared_ptr<Operation> right)
            : BinaryOperation(left, right) {}

};

class PowOperation final : public BinaryOperation {
    double apply(double left, double right) const override {
        return pow(left, right);
    }
public:
    PowOperation(const std::shared_ptr<Operation> left, const std::shared_ptr<Operation> right)
            : BinaryOperation(left, right) {}

};

#endif //CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_BINARYOPERATIONS_H
