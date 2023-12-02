#include <gtest/gtest.h>

// #include "Rhombus.h"

// TEST(constructor_test, without_exception_test_1) {
//     ASSERT_NO_THROW(Rhombus(Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1)));
// }

// TEST(constructor_test, without_exception_test_2) {
//     ASSERT_NO_THROW(Rhombus(Point(1.5, 1.5), Point(5.5, 1.5), Point(1.5, 5.5), Point(5.5, 5.5)));
// }

// TEST(copy_constructor_test, other_Rhombus_copy_test) {
//     Rhombus test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
//     Rhombus test_2 (test_1);

//     EXPECT_TRUE(test_1 == test_2);
// }

// TEST(move_constructor_test, other_Rhombus_move_test) {
//     Rhombus test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
//     Rhombus test_2 (std::move(test_1));

//     EXPECT_TRUE(test_1 == test_2);
// }

// TEST(assigment_operator_test, copy_assigment_test) {
//     Rhombus test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
//     Rhombus test_2 = test_1;

//     EXPECT_TRUE(test_1 == test_2);
// }

// TEST(assigment_operator_test, move_assigment_test) {
//     Rhombus test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
//     Rhombus test_2 = std::move(test_1);

//     EXPECT_TRUE(test_1 == test_2);
// }

// TEST(calculate_geometric_center_test, calculate_geometric_center_test_1) {
//     Rhombus test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
//     Point center_test = test_1.calculate_geometric_center();

//     EXPECT_DOUBLE_EQ(center_test.get_x(), 1);
//     EXPECT_DOUBLE_EQ(center_test.get_y(), 1);
// }

// TEST(calculate_geometric_center_test, calculate_geometric_center_test_2) {
//     Rhombus test_1 (Point(0, 0), Point(9, 0), Point(0,9), Point(9, 9));
//     Point center_test = test_1.calculate_geometric_center();

//     EXPECT_DOUBLE_EQ(center_test.get_x(), 4.5);
//     EXPECT_DOUBLE_EQ(center_test.get_y(), 4.5);
// }

// TEST(calculate_area_test, calculate_area_test_1) {
//     Rhombus test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));

//     EXPECT_DOUBLE_EQ(test_1.calculate_area(), 4);
// }

// TEST(equal_operator_test, true_return_1) {
//     Rhombus test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
//     Rhombus test_2 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));

//     EXPECT_TRUE(test_1 == test_2);
// }

// TEST(equal_operator_test, false_return_1) {
//     Rhombus test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
//     Rhombus test_2 (Point(0, 0), Point(4, 0), Point(0,4), Point(4, 4));

//     EXPECT_FALSE(test_1 == test_2);
// }

// TEST(non_equal_operator_test, true_return_1) {
//     Rhombus test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
//     Rhombus test_2 (Point(0, 0), Point(4, 0), Point(0,4), Point(4, 4));

//     EXPECT_TRUE(test_1 != test_2);
// }

// TEST(non_equal_operator_test, false_return_1) {
//     Rhombus test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
//     Rhombus test_2 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));

//     EXPECT_FALSE(test_1 != test_2);
// }

// TEST(rotated_Rhombus_tests, constructor_test_without_exception) {
//     ASSERT_NO_THROW(Rhombus(Point(2, 2), Point(4, 1), Point(3, 4), Point(5, 3)));
// }

// TEST(rotated_Rhombus_tests, calculate_geometric_center_test) {
//     Rhombus test_1 (Point(2, 2), Point(4, 1), Point(3, 4), Point(5, 3));
//     Point center_test = test_1.calculate_geometric_center();

//     EXPECT_DOUBLE_EQ(center_test.get_x(), 3.5);
//     EXPECT_DOUBLE_EQ(center_test.get_y(), 2.5);
// }

// TEST(rotated_Rhombus_tests, calculate_area_test) {
//     Rhombus test_1 (Point(2, 2), Point(4, 1), Point(3, 4), Point(5, 3));

//     EXPECT_DOUBLE_EQ(test_1.calculate_area(), 5);
// }
