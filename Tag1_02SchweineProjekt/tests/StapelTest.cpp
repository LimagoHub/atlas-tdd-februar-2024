//
// Created by JoachimWagner on 20.02.2024.
//

#include "StapelTest.h"

TEST_F(StapelTest, test1) {

    EXPECT_THAT(objectUnderTest.isEmpty(), Eq(true));
}

TEST_F(StapelTest, test2) {

    objectUnderTest.push(1);
    EXPECT_THAT(objectUnderTest.isEmpty(), Eq(false));
}
