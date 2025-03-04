#include <gtest/gtest.h>

// Simple test cases
TEST(MathTest, Addition) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(MathTest, Subtraction) {
    EXPECT_EQ(5 - 3, 2);
}

TEST(StringTest, Length) {
    std::string str = "hello";
    EXPECT_EQ(str.length(), 5);
}

TEST(StringTest, Compare) {
    std::string str1 = "hello";
    std::string str2 = "hello";
    EXPECT_EQ(str1, str2);
}
