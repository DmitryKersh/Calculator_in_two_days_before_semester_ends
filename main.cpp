#include <iostream>
#include "Parser.h"
#include "Counter.h"


using std::cout;

int main() {
    try{
        std::string expression;
        getline(std::cin, expression);
        cout << "You entered: " << expression << std::endl;
        std::queue<std::variant<double, OPERATIONS>> expression_queue =  parse_expression(expression);
        cout << "Result: " << count_expression(expression_queue) << std::endl;
    }
    catch (std::exception& e){
        cout << e.what() << std::endl;
    }

    return 0;
}