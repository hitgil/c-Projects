#include "../inc/operations.h"
int BitwiseOR(int number1, int number2)
{
    return (number1 | number2);
}

int BitwiseAND(int number1, int number2)
{
    return (number1 & number2);
}

int BitwiseNOT(int number1, int number2)
{
    number2 = 0;
    return ~number1;
}

int BitwiseXOR(int number1, int number2)
{
    return (number1 ^ number2);
}
