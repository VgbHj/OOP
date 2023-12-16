#include "gtest/gtest.h"

#include <Rhombus.h>

using pii = std::pair<double,double>;


TEST(rhombus_creator_test, without_exeption_test1){
    ASSERT_NO_THROW(Rhombus<double> rhomb({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)}));
}

TEST(rhombus_copy_constructor_test, other_Rhombus_copy_test) {
    Rhombus<double> test_1({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)});
    Rhombus<double> test_2 (test_1);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(rhombus_move_constructor_test, other_Rhombus_move_test) {
    Rhombus<double> test_1({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)});
    Rhombus<double> test_2 (std::move(test_1));

    EXPECT_TRUE(test_1 == test_2);
}

TEST(rhombus_assigment_operator_test, copy_assigment_test) {
    Rhombus<double> test_1({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)});
    Rhombus<double> test_2 = test_1;

    EXPECT_TRUE(test_1 == test_2);
}

TEST(rhombus_assigment_operator_test, move_assigment_test) {
    Rhombus<double> test_1({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)});
    Rhombus<double> test_2 = std::move(test_1);


    EXPECT_TRUE(test_1 == test_2);
}

TEST(rhombus_calculate_geometric_center_test, calculate_geometric_center_test_1) {
    
    Rhombus<double> test_1({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)});
    pii center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.first, 0);
    EXPECT_DOUBLE_EQ(center_test.second, 0);
}

TEST(rhombus_calculate_area_test, calculate_area_test_1) {
    Rhombus<double> test_1({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)});
   
    EXPECT_DOUBLE_EQ(test_1.calculate_area(), 392);
}

TEST(rhombus_equal_operator_test, true_return_1) {
    Rhombus<double> test_1({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)});
    Rhombus<double> test_2({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)});
   
    EXPECT_TRUE(test_1 == test_2);
}

TEST(rhombus_equal_operator_test, false_return_1) {
     Rhombus<double> test_1({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)});
    Rhombus<double> test_2({pii(14,14), pii(-14,0), pii(0,-14), pii(14,0)});
   
    EXPECT_FALSE(test_1 == test_2);
}

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}