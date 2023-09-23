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