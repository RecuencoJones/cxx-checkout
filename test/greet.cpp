#include "gtest/gtest.h"
#include "greet.h"

TEST(greet, test1) {
    EXPECT_EQ(greet("Test"), "Hello, Test!");
}