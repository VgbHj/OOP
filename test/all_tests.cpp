#include <gtest/gtest.h>

#include "RhombusCreator.h"
#include "HexagonCreator.h"
#include "PentagonCreator.h"
#include "FiguresArray.h"

// POINT

TEST(point_constructor_test, without_exception_test_1) {
    ASSERT_NO_THROW(Point(0, 0));
}

TEST(point_constructor_test, without_exception_test_2) {
    ASSERT_NO_THROW(Point(1.4, 10.8));
}

TEST(point_initializer_list_constructor_test, exception_test_1) {
    ASSERT_THROW(Point { 0 }, std::invalid_argument);
}

TEST(point_initializer_list_constructor_test, exception_test_2) {
    ASSERT_THROW(Point { 15.545 }, std::invalid_argument);
}

TEST(point_constructor_test, other_point_test_1) {
    Point test_1 {4, 5.2};
    Point test_2 (test_1);

    EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
    EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
}

TEST(point_constructor_test, other_point_test_2) {
    Point test_1 {2.28, 1.337};
    Point test_2 (test_1);

    EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
    EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
}

TEST(point_constructor_test, other_point_move_test_1) {
    Point test_1 {2.341, 43};
    Point test_2 (std::move(test_1));

    EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
    EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
}

TEST(point_constructor_test, other_point_move_test_2) {
    Point test_1 {4313.3, 454.53};
    Point test_2 (std::move(test_1));

    EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
    EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
}

TEST(point_assignment_operator_test, copy_assignment_test_1) {
    Point test_1 {4, 5.2};
    Point test_2 = test_1;

    EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
    EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
}

TEST(point_assignment_operator_test, copy_assignment_test_2) {
    Point test_1 {4313.3, 454.53};
    Point test_2 = test_1;

    EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
    EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
}

TEST(point_assignment_operator_test, move_assignment_test_1) {
    Point test_1 {2.341, 43};
    Point test_2 = std::move(test_1);

    EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
    EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
}

TEST(point_assignment_operator_test, move_assignment_test_2) {
    Point test_1 {4313.3, 454.53};
    Point test_2 = std::move(test_1);

    EXPECT_DOUBLE_EQ(test_1.get_x(), test_2.get_x());
    EXPECT_DOUBLE_EQ(test_1.get_y(), test_2.get_y());
}

TEST(point_get_cord_test, get_cord_test_1) {
    Point test_1 {134.5, 42.2};

    EXPECT_DOUBLE_EQ(test_1.get_x(), 134.5);
    EXPECT_DOUBLE_EQ(test_1.get_y(), 42.2);
}

TEST(point_get_cord_test, get_cord_test_2) {
    Point test_1 {224.54, 413};

    EXPECT_DOUBLE_EQ(test_1.get_x(), 224.54);
    EXPECT_DOUBLE_EQ(test_1.get_y(), 413);
}

TEST(point_set_cord_test, set_cord_test_1) {
    Point test_1 {0, 0};

    test_1.set_x(15);
    test_1.set_y(20);

    EXPECT_DOUBLE_EQ(test_1.get_x(), 15);
    EXPECT_DOUBLE_EQ(test_1.get_y(), 20);
}

TEST(point_set_cord_test, set_cord_test_2) {
    Point test_1 {15, 20};

    test_1.set_x(0);
    test_1.set_y(0);

    EXPECT_DOUBLE_EQ(test_1.get_x(), 0);
    EXPECT_DOUBLE_EQ(test_1.get_y(), 0);
}

TEST(point_equal_operator_test, true_return_1) {
    Point test_1 (0, 0);
    Point test_2 (0, 0);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(point_equal_operator_test, true_return_2) {
    Point test_1 (1, 54);
    Point test_2 (1, 54);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(point_equal_operator_test, false_return_1) {
    Point test_1 (0, 0);
    Point test_2 (1, 1);

    EXPECT_FALSE(test_1 == test_2);
}

TEST(point_equal_operator_test, false_return_2) {
    Point test_1 (34, 45.4);
    Point test_2 (4304.43, 41);

    EXPECT_FALSE(test_1 == test_2);
}

// RHOMBUS
TEST(rhombus_creator_test, with_exeption_test1){
    FigureCreator* rhombCreator = new RhombusCreator();
    ASSERT_THROW(rhombCreator->CreateFigure({Point(0,0), Point(-14,0), Point(0,-14), Point(14,0)}), std::invalid_argument);
}

TEST(rhombus_creator_test, without_exeption_test1){
    FigureCreator* rhombCreator = new RhombusCreator();
    ASSERT_NO_THROW(rhombCreator->CreateFigure({Point(0,14), Point(-14,0), Point(0,-14), Point(14,0)}));
}

TEST(rhombus_constructor_test, without_exception_test_1) {
    ASSERT_NO_THROW(Rhombus(Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1)));
}

TEST(rhombus_constructor_test, without_exception_test_2) {
    ASSERT_NO_THROW(Rhombus(Point(1.5, 1.5), Point(5.5, 1.5), Point(1.5, 5.5), Point(5.5, 5.5)));
}

TEST(rhombus_copy_constructor_test, other_Rhombus_copy_test) {
    Rhombus test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
    Rhombus test_2 (test_1);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(rhombus_move_constructor_test, other_Rhombus_move_test) {
    Rhombus test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
    Rhombus test_2 (std::move(test_1));

    EXPECT_TRUE(test_1 == test_2);
}

TEST(rhombus_assigment_operator_test, copy_assigment_test) {
    Rhombus test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
    Rhombus test_2 = test_1;

    EXPECT_TRUE(test_1 == test_2);
}

TEST(rhombus_assigment_operator_test, move_assigment_test) {
    Rhombus test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
    Rhombus test_2 = std::move(test_1);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(rhombus_calculate_geometric_center_test, calculate_geometric_center_test_1) {
    Rhombus test_1 (Point(0,14), Point(-14,0), Point(0,-14), Point(14,0));
    Point center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.get_x(), 0);
    EXPECT_DOUBLE_EQ(center_test.get_y(), 0);
}

TEST(rhombus_calculate_area_test, calculate_area_test_1) {
    Rhombus test_1 (Point(0,14), Point(-14,0), Point(0,-14), Point(14,0));

    EXPECT_DOUBLE_EQ(test_1.calculate_area(), 392);
}

TEST(rhombus_equal_operator_test, true_return_1) {
    Rhombus test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
    Rhombus test_2 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));

    EXPECT_TRUE(test_1 == test_2);
}

TEST(rhombus_equal_operator_test, false_return_1) {
    Rhombus test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
    Rhombus test_2 (Point(0, 0), Point(4, 0), Point(0,4), Point(4, 4));

    EXPECT_FALSE(test_1 == test_2);
}

// PENTAGON
TEST(pentagon_creator_test, with_exeption_test1){
    FigureCreator* pentCreator = new PentagonCreator();
    ASSERT_THROW(pentCreator->CreateFigure({Point(5,17), Point(-14,-10), Point(5,-17), Point(18,0)}), std::invalid_argument);
}

TEST(pentagon_creator_test, without_exeption_test1){
    FigureCreator* pentCreator = new PentagonCreator();
    ASSERT_NO_THROW(pentCreator->CreateFigure({Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0)}));
}

TEST(pentagon_constructor_test, without_exception_test_1) {
    ASSERT_NO_THROW(Pentagon(Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0)));
}

TEST(pentagon_constructor_test, without_exception_test_2) {
    ASSERT_NO_THROW(Pentagon(Point(5.1,17.1), Point(-14.1, 10.1), Point(-14.1,-10.1), Point(5.1,-17.1), Point(18.1,0)));
}

TEST(pentagon_copy_constructor_test, other_pentagon_copy_test) {
    Pentagon test_1 (Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));
    Pentagon test_2 (test_1);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(pentagon_move_constructor_test, other_pentagon_move_test) {
    Pentagon test_1 (Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));
    Pentagon test_2 (std::move(test_1));

    EXPECT_TRUE(test_1 == test_2);
}

TEST(pentagon_assigment_operator_test, copy_assigment_test) {
    Pentagon test_1 (Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));
    Pentagon test_2 = test_1;

    EXPECT_TRUE(test_1 == test_2);
}

TEST(pentagon_assigment_operator_test, move_assigment_test) {
    Pentagon test_1 (Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));
    Pentagon test_2 = std::move(test_1);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(pentagon_calculate_geometric_center_test, calculate_geometric_center_test_1) {
    Pentagon test_1 (Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));
    Point center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.get_x(), 0);
    EXPECT_DOUBLE_EQ(center_test.get_y(), 0);
}

TEST(pentagon_calculate_area_test, calculate_area_test_1) {
    Pentagon test_1 (Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));

    EXPECT_DOUBLE_EQ(test_1.calculate_area(), 581);
}

TEST(pentagon_equal_operator_test, true_return_1) {
    Pentagon test_1 (Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));
    Pentagon test_2 (Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));

    EXPECT_TRUE(test_1 == test_2);
}

TEST(pentagon_equal_operator_test, false_return_1) {
    Pentagon test_1 (Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));
    Pentagon test_2 (Point(1,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));

    EXPECT_FALSE(test_1 == test_2);
}

// HEXAGON
TEST(hexagon_creator_test, with_exeption_test1){
    FigureCreator* hexCreator = new HexagonCreator();
    ASSERT_THROW(hexCreator->CreateFigure({Point(2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0)}), std::invalid_argument);
}

TEST(hexagon_creator_test, without_exeption_test1){
    FigureCreator* hexCreator = new HexagonCreator();
    ASSERT_NO_THROW(hexCreator->CreateFigure({Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0)}));
}

TEST(hexagon_constructor_test, without_exception_test_1) {
    ASSERT_NO_THROW(Hexagon(Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0)));
}

TEST(hexagon_constructor_test, without_exception_test_2) {
    ASSERT_NO_THROW(Hexagon(Point(2.1,4.1), Point(-2.1,4.1), Point(-5.1,0), Point(-2.1,-4.1), Point(2.1,-4.1), Point(5.1,0)));
}

TEST(hexagon_copy_constructor_test, other_hexagon_copy_test) {
    Hexagon test_1 (Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));
    Hexagon test_2 (test_1);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(hexagon_move_constructor_test, other_hexagon_move_test) {
    Hexagon test_1 (Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));
    Hexagon test_2 (std::move(test_1));

    EXPECT_TRUE(test_1 == test_2);
}

TEST(hexagon_assigment_operator_test, copy_assigment_test) {
    Hexagon test_1 (Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));
    Hexagon test_2 = test_1;

    EXPECT_TRUE(test_1 == test_2);
}

TEST(hexagon_assigment_operator_test, move_assigment_test) {
    Hexagon test_1 (Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));
    Hexagon test_2 = std::move(test_1);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(hexagon_calculate_geometric_center_test, calculate_geometric_center_test_1) {
    Hexagon test_1 (Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));
    Point center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.get_x(), 0);
    EXPECT_DOUBLE_EQ(center_test.get_y(), 0);
}

TEST(hexagon_calculate_area_test, calculate_area_test_1) {
    Hexagon test_1 (Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));

    EXPECT_DOUBLE_EQ(test_1.calculate_area(), 32);
}

TEST(hexagon_equal_operator_test, true_return_1) {
    Hexagon test_1 (Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));
    Hexagon test_2 (Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));

    EXPECT_TRUE(test_1 == test_2);
}

TEST(hexagon_equal_operator_test, false_return_1) {
    Hexagon test_1 (Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));
    Hexagon test_2 (Point(1,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));

    EXPECT_FALSE(test_1 == test_2);
}

// ARRAY 

TEST(array_constructor_test, default_array_constructor_test) {
    FiguresArray f_arr; 
    EXPECT_EQ(f_arr.get_size(), 0);
}

TEST(array_constructor_test, initializer_array_constructor_test) {
    FiguresArray f_arr;

    Rhombus *rhomb = new Rhombus(Point(0,14), Point(-14,0), Point(0,-14), Point(14,0));
    Pentagon *pent = new Pentagon(Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));
    Hexagon *hex = new Hexagon(Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));
    f_arr.AddElement(rhomb);
    f_arr.AddElement(pent);
    f_arr.AddElement(hex);
    EXPECT_EQ(f_arr.get_size(), 3);
}

TEST(array_constructor_test, copy_array_constructor_test) {
    FiguresArray f_arr1;
    FiguresArray f_arr2;

    Rhombus *rhomb = new Rhombus(Point(0,14), Point(-14,0), Point(0,-14), Point(14,0));
    Pentagon *pent = new Pentagon(Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));
    Hexagon *hex = new Hexagon(Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));
    f_arr1.AddElement(rhomb);
    f_arr1.AddElement(pent);
    f_arr1.AddElement(hex);

    
    f_arr2 = f_arr1;

    for (size_t i = 0; i != f_arr1.get_size(); ++i) {
        EXPECT_EQ(f_arr1[i], f_arr2[i]);
    }
}