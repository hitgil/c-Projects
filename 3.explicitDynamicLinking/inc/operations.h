#ifndef OPERATION_H
#define OPERATION_H

extern "C"
{
    double addition(double number1, double number2);
    double subtraction(double number1, double number2);
    double multiplication(double number1, double number2);
    double division(double number1, double number2);
    double square(double number1, double number2);
    double squareRoot(double number1, double number2);
    double cube(double number1, double number2);
    double cubeRoot(double number1, double number2);

    int BitwiseOR(int number1, int number2);
    int BitwiseAND(int number1, int number2);
    int BitwiseNOT(int number1, int number2);
    int BitwiseXOR(int number1, int number2);

}

#endif