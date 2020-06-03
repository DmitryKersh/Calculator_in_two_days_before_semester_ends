

#ifndef CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_BINARYOPERATION_H
#define CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_BINARYOPERATION_H

#include "Operation.h"
#include <memory>
#include <utility>

class BinaryOperation : public Operation {
    std::shared_ptr<Operation> lhs;
    std::shared_ptr<Operation> rhs;
public:
    explicit BinaryOperation(std::shared_ptr<Operation>  lhs, std::shared_ptr<Operation> rhs) : lhs(std::move(lhs)), rhs(std::move(rhs)) {}
    double result() const override {
        return apply(lhs->result(), rhs->result());
    }
protected:
    virtual double apply(double left, double right) const = 0;
};

#endif //CALCULATOR_IN_TWO_DAYS_BEFORE_SEMESTER_ENDS_BINARYOPERATION_H
