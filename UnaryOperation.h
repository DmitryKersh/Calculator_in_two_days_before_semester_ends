#ifndef CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_UNARYOPERATION_H
#define CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_UNARYOPERATION_H
#include "Operation.h"
#include <memory>
#include <utility>

class UnaryOperation : public Operation {
    std::shared_ptr<Operation> operand;

public:
    explicit UnaryOperation(std::shared_ptr<Operation> operand) : operand(std::move(operand)) {}
    double result() const override { return apply(operand->result()); }

protected:
    virtual double apply(double arg) const = 0;
};

#endif //CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_UNARYOPERATION_H
