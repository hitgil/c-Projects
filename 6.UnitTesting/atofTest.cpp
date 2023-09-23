#include <gtest/gtest.h>
#include "Atof.cpp"

TEST(testOne, positiveInteger)
{
    ASSERT_DOUBLE_EQ(1, atof("1"));
    ASSERT_DOUBLE_EQ(0, atof("0000"));
    ASSERT_DOUBLE_EQ(10101, atof("010101"));
    ASSERT_DOUBLE_EQ(1000000000000000000, atof("1000000000000000000"));
}

TEST(testOne, negativeInteger)
{
    ASSERT_DOUBLE_EQ(-1, atof("-1"));
    ASSERT_DOUBLE_EQ(-0, atof("-0000"));
    ASSERT_DOUBLE_EQ(-10101, atof("-10101"));
    ASSERT_DOUBLE_EQ(-1000000000000000000, atof("-1000000000000000000"));
}

TEST(testOne, character)
{
    ASSERT_DOUBLE_EQ(0, atof("fg"));
    ASSERT_DOUBLE_EQ(1, atof("1fg45"));
    ASSERT_DOUBLE_EQ(0, atof("0fff 89"));
    ASSERT_DOUBLE_EQ(100, atof("100.f5"));
}

TEST(testOne, spaceFollowedBy)
{
    ASSERT_DOUBLE_EQ(0, atof(" fg45"));
    ASSERT_DOUBLE_EQ(123, atof(" 123"));
    ASSERT_DOUBLE_EQ(26, atof("      26"));
    ASSERT_DOUBLE_EQ(-10000, atof("      -10000f0000"));
}

TEST(testOne, doublePositiveNumber)
{
    ASSERT_DOUBLE_EQ(0, atof(" 0.0"));
    ASSERT_DOUBLE_EQ(1, atof(" 1.00"));
    ASSERT_DOUBLE_EQ(100.1, atof("100.1"));
    ASSERT_DOUBLE_EQ(10000.89, atof("10000.89f0000"));
}

TEST(testOne, doubleNegativeNumber)
{
    ASSERT_DOUBLE_EQ(-0, atof(" -0.0"));
    ASSERT_DOUBLE_EQ(-1, atof(" -1.00"));
    ASSERT_DOUBLE_EQ(-100.1, atof("-100.1"));
    ASSERT_DOUBLE_EQ(-10000.0000001, atof("-10000.0000001"));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
