
#include <iostream>
#include "../inc/calci.h"

void validation(char ch, double number1)
{
    double number2 = 0;
    double answer = 0;
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '&' || ch == '^' || ch == '|')
    {
        std::cin >> number2;
        answer = calculator(ch, number1, number2);
        std::cout << number1 << " " << ch << " " << number2 << " = " << answer << std::endl;
    }
    if (ch == '~' || ch == 's' || ch == 'c' || ch == 'r' || ch == 'q')
    {
        answer = calculator(ch, number1, number2);
        std::cout << number1 << " " << ch << " = " << answer << std::endl;
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
}

double calculator(char Operator, double number1, double number2)
{
    double answer;
    switch (Operator)
    {
    case '+':
    {
        answer = addition(number1, number2);
        break;
    }

    case '-':
    {
        answer = subtraction(number1, number2);
        break;
    }

    case '*':
    {
        answer = multiplication(number1, number2);
        break;
    }

    case '/':
    {
        answer = division(number1, number2);
        break;
    }
    case 's':
    {
        answer = square(number1);
        break;
    }
    case 'c':
    {
        answer = cube(number1);
        break;
    }
    case 'r':
    {
        answer = squareRoot(number1);
        break;
    }
    case 'q':
    {
        answer = cubeRoot(number1);
        break;
    }
    case '&':
    {
        answer = (double)Bitwise_AND(number1, number2);
        break;
    }
    case '|':
    {
        answer = (double)Bitwise_OR(number1, number2);
        break;
    }
    case '^':
    {
        answer = (double)Bitwise_XOR(number1, number2);
        break;
    }
    case '~':
    {
        answer = (double)Bitwise_NOT(number1);
        break;
    }
    default:
    {
        std::cout << "enter the valid input" << std::endl;
        break;
    }
    }
    return answer;
}