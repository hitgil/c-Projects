#include <iostream>
#include <gtest/gtest.h>
#include "../src/lib_basic.cpp"
#include "../src/lib_logical.cpp"
#include "../src/lib_multiplication.cpp"

TEST(basicTest, Addition)
{
    EXPECT_EQ(addition(10.0, 10.0), 20.0);
    EXPECT_EQ(addition(10.0, -10.0), 0.0);
    EXPECT_EQ(addition(-100.0, 10.0), -90.0);
    EXPECT_EQ(addition(-100.0, -10.0), -110.0);
}
TEST(basicTest, Subtraction)
{
    EXPECT_EQ(subtraction(10.0, 10.0), 0.0);
    EXPECT_EQ(subtraction(10.0, -10.0), 20.0);
    EXPECT_EQ(subtraction(-100.0, 10.0), -110.0);
    EXPECT_EQ(subtraction(-100.0, -10.0), -90.0);
}
TEST(basicTest, Division)
{
    EXPECT_EQ(division(10.0, 10.0), 1.0);
    EXPECT_EQ(division(10.0, -10.0), -1.0);
    EXPECT_EQ(division(-100.0, 10.0), -10.0);
    EXPECT_EQ(division(-100.0, -10.0), 10.0);
    // EXPECT_THROW(division(6.0, 0.0),std::runtime_error);
    // to check both exception and message
    EXPECT_THROW(
        try {
            division(6.0, 0.0);
        } catch (const std::runtime_error &e) {
            EXPECT_STREQ("Math error: Attempted to divide by Zero\n", e.what());
            throw;
        },
        std::runtime_error);

    EXPECT_EQ(division(-0.0, -10.0), 0.0);
}

TEST(MultiplicationTest, Multiplication)
{
    EXPECT_EQ(multiplication(10.0, 10.0), 100.0);
    EXPECT_EQ(multiplication(10.0, -10.0), -100.0);
    EXPECT_EQ(multiplication(-10.0, 10.0), -100.0);
    EXPECT_EQ(multiplication(-10.0, -10.0), 100.0);
    EXPECT_EQ(multiplication(-10.0, 0.0), 0.0);
}
TEST(MultiplicationTest, Square)
{
    EXPECT_EQ(square(10.0, 10.0), 100.0);
    EXPECT_EQ(square(-10.0, -10.0), 100.0);
    EXPECT_EQ(square(-10.0, 10.0), 100.0);
    EXPECT_EQ(square(-10000.0, -10.0), 100000000.0);
    EXPECT_EQ(square(-10.0, 0.0), 100);
}

TEST(MultiplicationTest, Cube)
{
    EXPECT_EQ(cube(10.0, 0.0), 1000.0);
    EXPECT_EQ(cube(-10.0, 0.0), -1000.0);
    EXPECT_EQ(cube(10000.0, 0.0), 1000000000000.0);
    EXPECT_EQ(cube(99.0, 0.0), 970299);
}

TEST(MultiplicationTest, CubeRoot)
{
    EXPECT_EQ(cubeRoot(8, 0), 2);
    EXPECT_EQ(cubeRoot(27, 0), 3.0000000000000004);
    EXPECT_EQ(cubeRoot(125, 0), 5);
    EXPECT_EQ(cubeRoot(-8, 0), -2);
    EXPECT_EQ(cubeRoot(-27, 0), -3.0000000000000004);
    EXPECT_EQ(cubeRoot(-125, 0), -5);
    EXPECT_EQ(cubeRoot(0, 0), 0);
}

TEST(MultiplicationTest, SquareRoot)
{
    EXPECT_EQ(squareRoot(4, 0), 2);
    EXPECT_EQ(squareRoot(25, 0), 5);
    EXPECT_EQ(squareRoot(100, 0), 10);
    EXPECT_TRUE(std::isnan(squareRoot(-4, 0)));
    EXPECT_TRUE(std::isnan(squareRoot(-25, 0)));
    EXPECT_TRUE(std::isnan(squareRoot(-100, 0)));
    EXPECT_EQ(squareRoot(0, 0), 0);
}
TEST(LogicalTest, logicalAnd)
{
    EXPECT_EQ(BitwiseAND(0, 0), 0);
    EXPECT_EQ(BitwiseAND(100.0, 0.0), 0);
    EXPECT_EQ(BitwiseAND(50, 100), 32);
    EXPECT_EQ(BitwiseAND(100, 100), 100);
    EXPECT_EQ(BitwiseAND(-100.0, 0.0), 0);
    EXPECT_EQ(BitwiseAND(-100, 50), 16);
    EXPECT_EQ(BitwiseAND(-100, 100), 4);
    EXPECT_EQ(BitwiseAND(-100, -100), -100);
}
TEST(LogicalTest, logicalOr)
{
    EXPECT_EQ(BitwiseOR(0, 0), 0);
    EXPECT_EQ(BitwiseOR(100.0, 0.0), 100);
    EXPECT_EQ(BitwiseOR(50, 100), 118);
    EXPECT_EQ(BitwiseOR(100, 100), 100);
    EXPECT_EQ(BitwiseOR(-100, 0), -100);
    EXPECT_EQ(BitwiseOR(-100, 50), -66);
    EXPECT_EQ(BitwiseOR(-100, 100), -4);
    EXPECT_EQ(BitwiseOR(-100, -100), -100);
}

TEST(LogicalTest, logicalNot)
{
    EXPECT_EQ(BitwiseNOT(0, 0), -1);
    EXPECT_EQ(BitwiseNOT(1, -100), -2);
    EXPECT_EQ(BitwiseNOT(100.0, 0), -101);
    EXPECT_EQ(BitwiseNOT(50, 0), -51);
    EXPECT_EQ(BitwiseNOT(-1, -100), 0);
    EXPECT_EQ(BitwiseNOT(-100, 0), 99);
    EXPECT_EQ(BitwiseNOT(-50, 50), 49);
    EXPECT_EQ(BitwiseNOT(-80, 100), 79);
}

TEST(LogicalTest, logicalXor)
{
    EXPECT_EQ(BitwiseXOR(0, 0), 0);
    EXPECT_EQ(BitwiseXOR(100.0, 0.0), 100);
    EXPECT_EQ(BitwiseXOR(50, 100), 86);
    EXPECT_EQ(BitwiseXOR(100, 100), 0);
    EXPECT_EQ(BitwiseXOR(-100, 0), -100);
    EXPECT_EQ(BitwiseXOR(-100, 50), -82);
    EXPECT_EQ(BitwiseXOR(100, -50), -86);
    EXPECT_EQ(BitwiseXOR(-100, -50), 82);
    EXPECT_EQ(BitwiseXOR(-100, 100), -8);
    EXPECT_EQ(BitwiseXOR(-100, -100), 0);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
