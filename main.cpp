#include <iostream>
#include "UnaryOperations.h"
#include "BinaryOperations.h"

using std::cout;

int main() {
  cout << UnaryMinusOperation(std::make_shared<CosinusOperation>(std::make_shared<ConstantOperation>(3))).result();
  cout << std::endl;
  cout << PowOperation(std::make_shared<ConstantOperation>(2), std::make_shared<ConstantOperation>(10)).result();
}