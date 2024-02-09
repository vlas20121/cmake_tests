#include "gtest/gtest.h"
#include "gtest/src/gtest-assertion-result.cc"
#include "gtest/src/gtest-death-test.cc"
#include "gtest/src/gtest-filepath.cc"
#include "gtest/src/gtest-matchers.cc"
#include "gtest/src/gtest-port.cc"
#include "gtest/src/gtest-printers.cc"
#include "gtest/src/gtest-test-part.cc"
#include "gtest/src/gtest-typed-test.cc"
#include "gtest/src/gtest.cc"


int Add(int a, int b)
{
    return a + b;
}


int Sub(int a, int b)
{
    return a - b;
}


int Mul(int a, int b)
{
    return a * b;
}


int Div(int a, int b)
{
    return a / b;
}


TEST(testSuite1, test1)
{
    ASSERT_EQ(1, 1) << "1 is equal 1";  //�����
}


TEST(testSuite1, test2)
{
    ASSERT_EQ(1, 0) << "1 is not equal 0";  //����������� �����, ����� �������� ���� �������    
}


TEST(testSuite1, test3)
{
    EXPECT_EQ(1, 1); //������, ��� 1 ����� 1, �����
    ASSERT_EQ(1, 1); //���������, ��� 1 ����� 1, �����
    EXPECT_EQ(1, 2); //������, ��� 1 ����� 2. ������������� �����, ���� ��������� ����������, �� ���� ��� ��������� "�����������".
    ASSERT_EQ(1, 2); //����������� �����, ����� �������� ���� �������
    ASSERT_EQ(1, 3); //�� ����������
}


TEST(testMath, testAdd)
{    
    //EXPECT_EQ(3, Add(1, 2));
    ASSERT_EQ(3, Add(1, 2));
}


TEST(testMath, testSub)
{
    //EXPECT_EQ(-1, Sub(1, 2));
    ASSERT_EQ(-1, Sub(1, 2));
}


TEST(testMath, testMul)
{
    //EXPECT_EQ(4, Mul(2, 2));
    ASSERT_EQ(4, Mul(2, 2));
}


TEST(testMath, testDiv)
{
    //EXPECT_EQ ���������� ����������, ���� ���� ������, ASSERT_EQ ����� ��������� ����.
    //� � ��� � ������ ������ ���� ��������� ���������, ������ EXPECT_EQ ��������� "�������" ������ ������
    //EXPECT_EQ(2.5, Div(5, 2));
    //EXPECT_EQ(3.5, Div(7, 2));
    ASSERT_EQ(2.5, Div(5, 2));
    ASSERT_EQ(3.5, Div(7, 2));
}


//��������� �����
TEST(testStr, testStr1)
{    
    ASSERT_STREQ("123", "123");
    std::string str1 = "1";
    str1 = str1 + "2";
    ASSERT_STREQ(str1.c_str(), "12");
    ASSERT_STRNE("123", "1234");
}


int main(int argc, char** argv)
{
    // ������ ��� ���������� �������� ��� �����
    // ��������� ���� ����� ��������� ��������� �������� ��������� ������ --gtest_filter
    // �������� --gtest_filter=testMath.testAdd �������� ������ ����� testAdd �� ������ testMath
    // --gtest_filter=* �������� ��� �����
        
    //printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    int code = RUN_ALL_TESTS();
    //getchar();
    return code;
}