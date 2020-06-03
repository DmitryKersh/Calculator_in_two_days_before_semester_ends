#include <iostream>
#include "UnaryOperations.h"

using std::cout;

int main() {
  cout << UnaryMinusOperation(std::make_shared<CosinusOperation>(std::make_shared<ConstantOperation>(3))).result();
}