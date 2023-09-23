#include "../inc/operations.h"
#include "cmath"

double multiplication(double number1, double number2)
{
    return number1 * number2;
}
double square(double number1, double number2)
{
    number2 = 0;
    return number1 * number1;
}
double cube(double number1,double number2)
{
    number2 = 0;
    return number1 * number1 * number1;
}
double squareRoot(double number1,double number2)
{
    number2 = 0;
    return sqrt(number1);
}
double cubeRoot(double number1,double number2)
{
    number2 = 0;
    return cbrt(number1);
}