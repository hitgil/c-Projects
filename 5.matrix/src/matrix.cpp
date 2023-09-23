#include"./header.h"
#include "./overload.h"

Matrix1::Matrix1(int a, int b)
{
    row = a;
    column = b;
    twoD = new int *[row];
    for (int i = 0; i < row; i++)
    {
        twoD[i] = new int[column];
    }
};
void Matrix1::setVal(int i, int j, const int &value)
{
    twoD[i][j] = value;
}
int &Matrix1::getVal(int i, int j)
{
    return twoD[i][j];
}
void Matrix1::setMatrix()
{
    for (int i = 0; i < row; i++)
    {
        std::cout << "enter the entries for row " << i << std::endl;
        for (int j = 0; j < column; j++)
        {
            int value;
            std::cin >> value;
            if(isdigit(value)){
                std::cerr<<"invalid entry"<<std::endl;
            }

            setVal(i, j, value);
        }
    }
}
void Matrix1::displayMat()
    {
        std::cout << "ROW:" << row << "  COLUMN:" << column << std::endl;
        for (int i = 0; i < row; i++)
        {
            std::cout << "|";
            for (int j = 0; j < column; j++)
            {
                std::cout << getVal(i, j);
            }
            std::cout << "|\n";
        }
    }
    Matrix1 &operator+(Matrix1 &obj1, const Matrix1 &obj2)
{
    if (obj1.row != obj2.row || obj1.column != obj2.column)
    {
        std::cout << "both the matrix must be of same dimension" << std::endl;
        exit(0);
    }
    for (int i = 0; i < obj1.row; i++)
        for (int j = 0; j < obj1.column; j++)
        {
            obj1.twoD[i][j] = obj1.twoD[i][j] + obj2.twoD[i][j];
        }
    return obj1;
}
Matrix1 operator*(const Matrix1 &obj1, const Matrix1 &obj2)
{
    if (obj1.column != obj2.row)
    {
        throw std::invalid_argument(" first matrix must have the same number of columns as the second matrix has rows");
    }

    Matrix1 result(obj1.row, obj2.column);
    for (int i = 0; i < result.row; i++)
        for (int j = 0; j < result.column; j++)
        {
            int sum = 0;
            for (int k = 0; k < obj1.column; k++)
            {
                sum += obj1.twoD[i][k] * obj2.twoD[k][j];
            }
            result.twoD[i][j] = sum;
        }
    return result;
}