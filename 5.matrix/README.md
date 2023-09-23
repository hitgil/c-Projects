# Matrix Multiplication and Addition Program

This C++ program allows you to perform matrix multiplication and addition operations on two matrices.


## Matrix Class

The Matrix1 class is used to represent matrices. It includes the following methods:

- Matrix1(int a, int b): Constructor to create a matrix with a rows and b columns.
- void setVal(int i, int j, const int &value): Set the value of the matrix element at row i and column j.
- int &getVal(int i, int j): Get the value of the matrix element at row i and column j.
- void setMatrix(): Input values for each element of the matrix.
- void displayMat(): Display the matrix on the screen.
- Overloaded + and * operators for matrix addition and multiplication.

## Matrix Operations

You can perform two types of matrix operations:

- Matrix Multiplication: Multiply two matrices of compatible dimensions.
- Matrix Addition: Add two matrices of the same dimensions.