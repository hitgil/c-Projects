#ifndef OVERLOAD_H
#define OVERLOAD_H
#include"./header.h"

Matrix1 &operator+(Matrix1 &obj1, const Matrix1 &obj2);
Matrix1 operator*(const Matrix1 &obj1, const Matrix1 &obj2);

#endif