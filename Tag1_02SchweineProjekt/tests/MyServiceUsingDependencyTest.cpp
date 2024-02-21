//
// Created by JoachimWagner on 20.02.2024.
//

#include "MyServiceUsingDependencyTest.h"
#include "iostream"
TEST_F(MyServiceUsingDependencyTest, demo) {



    // RecordMode
    EXPECT_CALL(dependencyMock, isSolvent(_)).WillRepeatedly(Return(true));
    EXPECT_CALL(dependencyMock, isSolvent("Hello")).WillOnce(Return(false));


    // Replay
    std::cout << dependencyMock.isSolvent("Hallo") << std::endl;
    std::cout << dependencyMock.isSolvent("Hello") << std::endl;


    //EXPECT_THAT(objectUnderTest.bar(), Eq(100));
}

/*TEST_F(MyServiceUsingDependencyTest, demo2) {

    // RecordMode
    EXPECT_CALL(dependencyMock, isSolvent).WillOnce(Return(false));
    // Replay

    EXPECT_THAT(objectUnderTest.bar(), Eq(-100));
}

TEST_F(MyServiceUsingDependencyTest, demo3) {

    // RecordMode
    EXPECT_CALL(dependencyMock, isSolvent).WillOnce(Throw(std::exception{"upps"}));
    // Replay

    EXPECT_THAT(objectUnderTest.bar(), Eq(-100));
}
*/
