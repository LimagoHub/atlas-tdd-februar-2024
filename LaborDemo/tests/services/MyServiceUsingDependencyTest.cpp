//
// Created by JoachimWagner on 11.07.2024.
//

#include "MyServiceUsingDependencyTest.h"




TEST_F(MyServiceUsingDependencyTest, MockdemoFooFunc) {

    // Arrange
    //RecordMode
    EXPECT_CALL(dependencyMock, foo("HALLO"));
    //ReplayMode

    //Act
    objectUnderTest.f("Hallo");
}


TEST_F(MyServiceUsingDependencyTest, MockdemoFooBarFunc) {

    EXPECT_CALL(dependencyMock, bar()).WillOnce(Return(10)).WillOnce(Return(2));

    auto result = objectUnderTest.h();

    EXPECT_THAT(result, Eq(20));


}

TEST_F(MyServiceUsingDependencyTest, f_Upper) {

    // Recordmode
    EXPECT_CALL(dependencyMock,foo("HALLO"));
    //EXPECT_CALL(dependencyMock,foo("XYZ"));
    // Replaymode

    objectUnderTest.f("hallo");

}

TEST_F(MyServiceUsingDependencyTest, f_Murks) {

    // Recordmode
    EXPECT_CALL(dependencyMock,foobar(EndsWith("Welt"))).WillOnce(Return(100));




    auto result = objectUnderTest.g("Hello");
    EXPECT_THAT(result, 105);
}

void MyServiceUsingDependencyTest::SetUp() {
    ON_CALL(dependencyMock,foobar(testing::_)).WillByDefault(Return(2000));
}
