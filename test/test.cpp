#include <gtest/gtest.h>
#include "Six.h"


TEST(constructor_test, without_exception_test) {
    ASSERT_NO_THROW(Six(10, '5'));
}

TEST(initializer_list_constructor_test, exception_test) {
    ASSERT_NO_THROW(Six {'1'});
}
TEST(string_constructor_test, without_exception_test_1) {
    ASSERT_NO_THROW(Six{ "555" });
}

TEST(to_DEC_test, test1) {
    Six test { "5555" };
    uint64_t dec_num = test.BASE_to_int();
    testing::internal::CaptureStdout();
    std::cout << dec_num << std::endl;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1295\n");
}


TEST(to_BASE_test, test1) {
    Six test { "5555" };
    std::string BASE_num = test.int_to_BASE(1295);
    testing::internal::CaptureStdout();
    std::cout << BASE_num << std::endl;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5555\n");
}


TEST(operator_plus_equal_test, test1) {
    Six test_a { "5555" };
    Six test_b { "1" };
    test_a += test_b;
    testing::internal::CaptureStdout();
    std::cout << test_a;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10000");
}

TEST(operator_minus_equal_test, test1) {
    Six test_a { "5555" };
    Six test_b { "1" };
    test_a -= test_b;
    testing::internal::CaptureStdout();
    std::cout << test_a;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5554");
}

TEST(operator_post_inc_test, test1) {
    Six test{ "5555" };
    test++;
    testing::internal::CaptureStdout();
    std::cout << test;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10000");
}

TEST(operator_post_dec_test, test1) {
    Six test{ "5555" };
    test--;
    testing::internal::CaptureStdout();
    std::cout << test;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5554");
}

TEST(comparison_operator_test, zero_true_test) {
    Six first{ "0" };
    Six second{ "0" };

    ASSERT_TRUE(first == second);
}

TEST(false_comparison_operator_test, true_return) {
    Six first{ "0" };
    Six second{ "1" };

    ASSERT_TRUE(first != second);
}


TEST(more_operator_test, false_return) {
    Six first{ "555" };
    Six second{ "1" };

    ASSERT_TRUE(first > second);
}


TEST(less_operator_test, true_return) {
    Six first{ "1" };
    Six second{ "555" };

    ASSERT_TRUE(first < second);
}


TEST(more_or_equal_operator_test, true_return) {
    Six first{ "1" };
    Six second{ "1" };

    ASSERT_TRUE(first >= second);
}

TEST(more_or_equal_operator_test, false_return) {
    Six first{ "2" };
    Six second{ "1" };

    ASSERT_TRUE(first >= second);
}

TEST(less_or_equal_operator_test, true_return) {
    Six first{ "1" };
    Six second{ "1" };

    ASSERT_TRUE(first <= second);
}

TEST(less_or_equal_operator_test, false_return) {
    Six first{ "1" };
    Six second{ "2" };

    ASSERT_TRUE(first <= second);
}

TEST(print_test, test1) {
    Six test{ "0" };
    testing::internal::CaptureStdout();
    std::cout << test;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0");
}
