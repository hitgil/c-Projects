#include <gmock/gmock.h>

class IA
{
    virtual bool foo() = 0;

public:
    virtual bool fooOne() = 0;
};

class MockB : public IA
{

    bool foo() override { return true; };

public:
    bool fooOne() override
    {
        std::cout << "hello\n";
        return foo();
    };
};

class MockA : public IA
{
public:
    bool fooOne()
    {
        std::cout << "KV/n";
        return true;
    }
    MOCK_METHOD(bool, fooOne, ()); // gmock_fooOne
    
    MOCK_METHOD(bool, foo, ());
};

class B
{
    IA *a;

public:
    B(IA *a) : a(a){};
    // B(){};
    bool fooTwo()
    {
        return a->fooOne();
    };

    // virtual bool isEven(int number)
    // {

    //     bool isEven = (number % 2 == 0);
    //     return isEven;
    // }
    ~B(){};
};

TEST(MockBank, testToCheckFooOneIsCalled)
{

    MockA mockA;
    IA *ptrA = &mockA;
    B b(ptrA);
    // mockA.fooOne();

    EXPECT_CALL(mockA, fooOne()).Times(::testing::AtLeast(1)).WillOnce(::testing::Return(true)); //
    // ((mockA)gmock_fooOne())(::::testing::internal::GetWithoutMatchers(), nullptr) .InternalExpectedAt("test.cpp", 38,"mockA" ,"fooOne()")
    EXPECT_CALL(mockA, fooOne()).Times(::testing::AtLeast(1)).WillOnce(::testing::Return(false)); //

    bool didCall = b.fooTwo();
    EXPECT_TRUE(didCall);
}

// class ParamTestForIsEven : public ::testing::TestWithParam<int>
// {
// protected:
//     B b;
// };

// INSTANTIATE_TEST_SUITE_P(, ParamTestForIsEven, ::testing::Values(2, 4, 6, 8, 10));

// TEST_P(ParamTestForIsEven, NumberIsEven)
// {
//     int evenNumber = GetParam();
//     ASSERT_TRUE(b.isEven(evenNumber));
// }

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}