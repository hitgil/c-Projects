
#include <iostream>
#include <dlfcn.h>

double calculator(char Operator, double number1, double number2)
{

    void *handle = dlopen("./calculator.so", RTLD_LAZY);

    if (!handle)
    {
        std::cerr << "ERROR LOADING LIBRARY:" << dlerror() << std::endl;
        return EXIT_FAILURE;
    }
    double(*addition)(double,double) = (double (*)(double, double))dlsym(handle, "addition");
    auto subtraction = (double (*)(double, double))dlsym(handle, "subtraction");
    auto multiplication = (double (*)(double, double))dlsym(handle, "multiplication");
    auto division = (double (*)(double, double))dlsym(handle, "division");
    auto BitwiseAND = (int (*)(int, int))dlsym(handle, "BITWISE_AND");
    auto BitwiseOR = (int (*)(int, int))dlsym(handle, "BITWISE_OR");
    auto BitwiseXOR = (int (*)(int, int))dlsym(handle, "BITWISE_XOR");
    auto BitwiseNOT = (int (*)(int,int))dlsym(handle, "BITWISE_NOT");
    auto square = (double (*)(double, double))dlsym(handle, "square");
    auto cube = (double (*)(double, double))dlsym(handle, "cube");
    auto squareRoot = (double (*)(double, double))dlsym(handle, "squareRoot");
    auto cubeRoot = (double (*)(double, double))dlsym(handle, "cubeRoot");

    const char *dlsym_error = dlerror();
    if (dlsym_error)
    {

        std::cerr << "Error loading symbols: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }
    int (*logicalOperation[10])(int, int) = { BitwiseAND, BitwiseNOT, BitwiseOR, BitwiseXOR };
    double (*AthematicOperation[10])(double, double) = {addition, subtraction, division, multiplication, squareRoot, cubeRoot, square, cube};

    double answer;

    switch (Operator)
    {case '+':
        {
            // answer = (*AthematicOperation[0])(number1, number2);
            return addition(number1,number2);
            break;
        }

        case '-':
        {
            answer = (*AthematicOperation[1])(number1, number2);
            break;
        }

        case '*':
        {
            answer = (*AthematicOperation[3])(number1, number2);
            break;
        }

        case '/':
        {
            answer = (*AthematicOperation[2])(number1, number2);
            break;
        }
        case 's':
    {
        answer = (*AthematicOperation[6])(number1, 0);
        break;
    }
    case 'c':
    {
        answer = (*AthematicOperation[7])(number1, 0);
        break;
    }
    case 'r':
    {
        answer = (*AthematicOperation[4])(number1, 0);
        break;
    }
    case 'q':
    {
        answer = (*AthematicOperation[5])(number1, 0);
        break;
    }
    case '&':
    {
        answer = (*AthematicOperation[0])(number1,number2);
        break;
    }
    case '|':
    {
        answer = (*AthematicOperation[2])(number1,number2);
        break;
    }
    case '^':
    {
        answer = (*AthematicOperation[3])(number1,number2);
        break;
    }
    case '~':
    {
        answer = (*AthematicOperation[1])(number1,number2);
        break;
    }
    default:
    {
        std::cout << "error" << std::endl;
        break;
    }
    }
    return answer;
    dlclose(handle);
}