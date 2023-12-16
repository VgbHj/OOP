#include <gtest/gtest.h>

#include <memory>
#include <Figure.h>
#include <Rhombus.h>
#include <Pentagon.h>
#include <Hexagon.h>
#include <Array.h>


using pii = std::pair<double,double>;

TEST(constructor_test, default_constructor_test) {
    Array<std::shared_ptr<Figure<double>>> test_1; 

    EXPECT_EQ(test_1.size(), 0);
}

TEST(constructor_test, initializer_constructor_test) {
    Array<std::shared_ptr<Figure<double>>> arr({
        std::make_shared<Rhombus<double>>(pii(0,14), pii(-14,0), pii(0,-14), pii(14,0))
    });


    EXPECT_EQ(arr.size(), 1);
}

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}