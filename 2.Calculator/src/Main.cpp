#include <iostream>
#include "../inc/calci.h"

extern double calculator(const char &Operator, const double &number1, const double &number2);
extern void validation(char ch, double number1);

int main()
{

    double number1 = 0;
    double number2 = 0;
    double answer = 0;
    char ch;
    std::cout << "           CALCULATOR              " << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "         + for addition            " << std::endl;
    std::cout << "         - for subtraction         " << std::endl;
    std::cout << "         * for multiplication      " << std::endl;
    std::cout << "         / for division            " << std::endl;
    std::cout << "         s for square              " << std::endl;
    std::cout << "         c for cube                " << std::endl;
    std::cout << "         r for square root         " << std::endl;
    std::cout << "         q for cube root           " << std::endl;
    std::cout << "         & for logicalAND          " << std::endl;
    std::cout << "         | for logicalOR           " << std::endl;
    std::cout << "         ^ for logicalXOR          " << std::endl;
    std::cout << "         ~ for logicalNOT          " << std::endl;
    std::cout << "---------------------------------- "
              << std::endl;
    std::cout << "              INPUT                 " << std::endl;
    std::cout << "-----------------------------------\n"
              << std::endl;
    std::cin >> number1;
    std::cin >> ch;
    validation(ch, number1);
    return 0;
}