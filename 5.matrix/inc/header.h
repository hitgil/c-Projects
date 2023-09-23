#ifndef HEADER_H
#define HEADER_H

#include <iostream>

class Matrix1
{
    int row;
    int column;
    int **twoD;

public:
    friend Matrix1 &operator+(Matrix1 &obj1, const Matrix1 &obj2);
    friend Matrix1 operator*(const Matrix1 &obj1, const Matrix1 &obj2);
    Matrix1(const Matrix1 &m) : row(m.row), column(m.column), twoD(m.twoD){};
    Matrix1(int a, int b);
    void setVal(int i, int j, const int &value);
    int &getVal(int i, int j);
    void setMatrix();
    void displayMat();
    ~Matrix1(){}
};

#endif