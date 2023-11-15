#include <gtest/gtest.h>
#include <calc.h>

TEST(basic_test_set, test_01)
{
    ASSERT_TRUE(sum_of_bin_range(2,7)==11);
}

TEST(basic_test_set, test_02)
{
    ASSERT_TRUE(sum_of_bin_range(0,1)==1);
}

TEST(basic_test_set, test_03)
{
    ASSERT_TRUE(sum_of_bin_range(-7,-2)==11);
}

TEST(basic_test_set, test_04)
{
    ASSERT_TRUE(sum_of_bin_range(1,1)==1);
}

class SumOfBinRangeParametersTests :public ::testing::TestWithParam<std::tuple<int, int, int>> {};

TEST_P(SumOfBinRangeParametersTests, SumOfBinTests) {
    int a = std::get<0>(GetParam());
    int b = std::get<1>(GetParam());
    int ans = std::get<2>(GetParam());
    int expected = sum_of_bin_range(a, b);
    ASSERT_EQ(expected, ans);
}

INSTANTIATE_TEST_CASE_P(
        SumOfBinTests,
        SumOfBinRangeParametersTests,
        ::testing::Values(
                std::make_tuple(2, 7, 11),
                std::make_tuple(0, 1, 1),
                std::make_tuple(-7, -2, 11),
                std::make_tuple(0, 0, 0)
                ));