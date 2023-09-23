#include <iostream>
#include <dlfcn.h>
#include "../inc/operations.h"

double calculator(char ch, double number1, double number2);
void validation(char ch, double number1);

int main()
{   double number1 = 0;
    double number2 = 0;
    double answer = 0;
    char next;
    char ch;
    do{
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
    validation(ch,number1);
    std::cout << "(Y/y)=>continue (N/n)=>exit" << std::endl;
    std::cin>>next;
    }
    while (next=='y'||next=='Y');
    
    return 0;
}