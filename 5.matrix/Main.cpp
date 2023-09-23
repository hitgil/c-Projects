
#include "./overload.h"
#include "./header.h"

class Matrix;
int main()
{
    char ch;
    int row1 = 0;
    int column1 = 0;
    int row2 = 0;
    int column2 = 0;
    std::cout << "enter the number of rows and columns for 1st matrix" << std::endl;
    std::cin >> row1 >> column1;
    Matrix1 M1(row1, column1);
    M1.setMatrix();
    M1.displayMat();
    std::cout << "enter the number of rows and columns for 2st matrix" << std::endl;
    std::cin >> row2 >> column2;
    Matrix1 M2(row2, column2);
    M2.setMatrix();
    M2.displayMat();
    std::cout << "press \e[1m * \e[0m for multiplication and \e[1m + \e[0m for addition" << std::endl;
    Matrix1 M3(row1, column2);
    std::cin >> ch;

    switch (ch)
    {
        case '*':
        {
            M3 = M1 * M2;
            break;
        }
        case '+':
        {
            M3 = M1 + M2;
            break;
        }
        default:
            std::cout << "invalid input" << std::endl;
            break;
    };
    std::cout << "resulting matrix is " << std::endl;
    M3.displayMat();
    return 0;
}