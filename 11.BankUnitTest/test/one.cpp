#include <gmock/gmock.h>

class A
{
public:
    // int foo(){return 2;};
    int foo()
    {
        std::cout << "hello";
        return 1;
    }
};
class MockA : public A
{
public:
    // int foo(){return 90;};
    // int foo(){std::cout<<"namsthe";
    //     return 1;
    // }
    MOCK_METHOD(int, foo, ());
};

class B
{
    A &a;

public:
    B(A &a) : a(a) {}

    int fooOne()
    {
        std::cout << "namsthe";
        return a.foo();
    }
};

TEST(btest, CheckIfFooOneIsCalled)
{
    MockA mocka;
    B b(mocka);

    EXPECT_CALL(mocka, foo()).Times(1).WillOnce(::testing::Return(1));
    int result = b.fooOne();
    
    EXPECT_TRUE(result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}