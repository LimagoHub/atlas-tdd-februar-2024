//
// Created by JoachimWagner on 30.12.2023.
//
#include "gtest/gtest.h"


TEST(TestCaseName, TestName) {
    ASSERT_EQ(1, 1); // Terminiert den Test beim Scheitern
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}
