
#include <iostream>
extern double calculator(char ch, double number1, double number2);
extern void validation(char ch, double number1);

void validation(char ch, double number1)
{
    int number2 =0 ;
    int answer =0;
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '&' || ch == '^' || ch == '|')
    {
        std::cin >> number2;
        answer = calculator(ch, number1, number2);
        std::cout << number1 << " " << ch << " " << number2 << " = " << answer << std::endl;
    }
    else if (ch == '~' || ch == 's' || ch == 'c' || ch == 'r' || ch == 'q')
    {
        answer = calculator(ch, number1, number2);
        std::cout << number1 << " " << ch << " = " << answer << std::endl;
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
    }

}