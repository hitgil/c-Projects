#include<iostream>
#include <gtest/gtest.h>
#include "inc/matrix.h"

class basicTest : public ::testing::Test
{
protected:
    Matrix *objOnePointer;
    Matrix *objTwoPointer;
    Matrix *objThreePointer;
    void SetUp() override
    {
        objOnePointer = new Matrix(2, 2);
        objOnePointer->setVal(0, 0, 1);
        objOnePointer->setVal(0, 1, 1);
        objOnePointer->setVal(1, 0, 1);
        objOnePointer->setVal(1, 1, 1);

        objTwoPointer = new Matrix(2, 2);
        objTwoPointer->setVal(0, 0, 2);
        objTwoPointer->setVal(0, 1, 2);
        objTwoPointer->setVal(1, 0, 2);
        objTwoPointer->setVal(1, 1, 2);
        objThreePointer = new Matrix(2, 2);
    }
    void TearDown() override
    {
        delete objOnePointer;
        delete objTwoPointer;
        delete objThreePointer;
        std::cout<<"------------------------TEST END--------------------------<<std::endl
    }
};

TEST_F(basicTest, Addition)
{
    *objThreePointer = *objOnePointer + *objTwoPointer;
    EXPECT_EQ(objThreePointer->getVal(0, 0), 3);
    EXPECT_EQ(objThreePointer->getVal(0, 1), 3);
    EXPECT_EQ(objThreePointer->getVal(1, 0), 3);
    EXPECT_EQ(objThreePointer->getVal(1, 1), 3);
}

TEST_F(basicTest, Multiplication)
{
    *objThreePointer = (*objOnePointer) * (*objTwoPointer);

    EXPECT_EQ(objThreePointer->getVal(0, 0), 4);
    EXPECT_EQ(objThreePointer->getVal(0, 1), 4);
    EXPECT_EQ(objThreePointer->getVal(1, 0), 4);
    EXPECT_EQ(objThreePointer->getVal(1, 1), 4);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
