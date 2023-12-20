// #include <gtest/gtest.h>

// #include "Point.h"

// TEST(constructor_test, without_exception_test_1) {
//     ASSERT_NO_THROW(Point(0, 0));
// }

// TEST(constructor_test, without_exception_test_2) {
//     ASSERT_NO_THROW(Point(1.4, 10.8));
// }

// TEST(initializer_list_constructor_test, exception_test_1) {
//     ASSERT_THROW(Point { 0 }, std::invalid_argument);
// }

// TEST(initializer_list_constructor_test, exception_test_2) {
//     ASSERT_THROW(Point { 15.545 }, std::invalid_argument);
// }

// TEST(constructor_test, other_point_test_1) {
//     Point test_1 {4, 5.2};
//     Point test_2 (test_1);

//     EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
//     EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
// }

// TEST(constructor_test, other_point_test_2) {
//     Point test_1 {2.28, 1.337};
//     Point test_2 (test_1);

//     EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
//     EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
// }

// TEST(constructor_test, other_point_move_test_1) {
//     Point test_1 {2.341, 43};
//     Point test_2 (std::move(test_1));

//     EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
//     EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
// }

// TEST(constructor_test, other_point_move_test_2) {
//     Point test_1 {4313.3, 454.53};
//     Point test_2 (std::move(test_1));

//     EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
//     EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
// }

// TEST(assignment_operator_test, copy_assignment_test_1) {
//     Point test_1 {4, 5.2};
//     Point test_2 = test_1;

//     EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
//     EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
// }

// TEST(assignment_operator_test, copy_assignment_test_2) {
//     Point test_1 {4313.3, 454.53};
//     Point test_2 = test_1;

//     EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
//     EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
// }

// TEST(assignment_operator_test, move_assignment_test_1) {
//     Point test_1 {2.341, 43};
//     Point test_2 = std::move(test_1);

//     EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
//     EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
// }

// TEST(assignment_operator_test, move_assignment_test_2) {
//     Point test_1 {4313.3, 454.53};
//     Point test_2 = std::move(test_1);

//     EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
//     EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
// }

// TEST(get_cord_test, get_cord_test_1) {
//     Point test_1 {134.5, 42.2};

//     EXPECT_DOUBLE_EQ(test_1.get_x(), 134.5);
//     EXPECT_DOUBLE_EQ(test_1.get_y(), 42.2);
// }

// TEST(get_cord_test, get_cord_test_2) {
//     Point test_1 {224.54, 413};

//     EXPECT_DOUBLE_EQ(test_1.get_x(), 224.54);
//     EXPECT_DOUBLE_EQ(test_1.get_y(), 413);
// }

// TEST(set_cord_test, set_cord_test_1) {
//     Point test_1 {0, 0};

//     test_1.set_x(15);
//     test_1.set_y(20);

//     EXPECT_DOUBLE_EQ(test_1.get_x(), 15);
//     EXPECT_DOUBLE_EQ(test_1.get_y(), 20);
// }

// TEST(set_cord_test, set_cord_test_2) {
//     Point test_1 {15, 20};

//     test_1.set_x(0);
//     test_1.set_y(0);

//     EXPECT_DOUBLE_EQ(test_1.get_x(), 0);
//     EXPECT_DOUBLE_EQ(test_1.get_y(), 0);
// }

// TEST(equal_operator_test, true_return_1) {
//     Point test_1 (0, 0);
//     Point test_2 (0, 0);

//     EXPECT_TRUE(test_1 == test_2);
// }

// TEST(equal_operator_test, true_return_2) {
//     Point test_1 (1, 54);
//     Point test_2 (1, 54);

//     EXPECT_TRUE(test_1 == test_2);
// }

// TEST(equal_operator_test, false_return_1) {
//     Point test_1 (0, 0);
//     Point test_2 (1, 1);

//     EXPECT_FALSE(test_1 == test_2);
// }

// TEST(equal_operator_test, false_return_2) {
//     Point test_1 (34, 45.4);
//     Point test_2 (4304.43, 41);

//     EXPECT_FALSE(test_1 == test_2);
// }