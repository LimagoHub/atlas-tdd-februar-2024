//
// Created by JoachimWagner on 20.02.2024.
//

#include "StapelTest.h"
//                 MethodenName__Fall__Erwartung
TEST_F(StapelTest, isEmpty__EmptyStack__returnsTrue) {
    // Arrange


    // Act
    auto result = objectUnderTest.isEmpty();

    // Assertion
    EXPECT_TRUE(result);

}

TEST_F(StapelTest, isEmpty__NotEmptyStack__returnsFalse) {
    // Arrange
    const int validValue = 10;

    objectUnderTest.push(validValue);

    // Act
    auto result = objectUnderTest.isEmpty();

    // Assertion
    EXPECT_FALSE(result);

}

TEST_F(StapelTest, push__fillUpToMaximum__noExceptionIsThrown) {
    // Arrange
    // Act + Assertion
    const int validValue = 10;

    fillUpToLimitWithoutException();

}

TEST_F(StapelTest, push__Overflow__StapelExceptionIsThrown) {
    // Arrange

    const int validValue = 10;

    fillUpToLimitWithoutException();

    // Act + Assertion
    EXPECT_THROW(objectUnderTest.push(validValue), StapelException);

}

TEST_F(StapelTest, push__Overflow__StapelExceptionIsThrown_variante){
    try {
        fillUpToLimitWithoutException();
        objectUnderTest.push(1);
        FAIL() << "Fehler: StapelException erwartet";
    }catch(const StapelException & ex) {
        EXPECT_STREQ("Overflow", ex.what());
    }

}

TEST_F(StapelTest, isFull__FullStack__returnsTrue) {
    // Arrange
    fillUpToLimitWithoutException();

    // Act
    auto result = objectUnderTest.isFull();

    // Assertion
    EXPECT_TRUE(result);

}
TEST_F(StapelTest, isFull__NotFullStack__returnsFalse) {
    // Arrange
    // Ok

    // Act
    auto result = objectUnderTest.isFull();

    // Assertion
    EXPECT_FALSE(result);

}
