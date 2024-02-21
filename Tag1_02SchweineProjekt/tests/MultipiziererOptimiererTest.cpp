//
// Created by JoachimWagner on 21.02.2024.
//

#include "MultipiziererOptimiererTest.h"


TEST_F(MultipiziererOptimiererTest, mult__aLtb__firstAThenBpassedToService){
    EXPECT_CALL(multipliziererMock, mult(1,1000));

    objectUnderTest.mult(1,1000);
}


TEST_F(MultipiziererOptimiererTest, mult__aGeb__firstAThenBpassedToService){
    EXPECT_CALL(multipliziererMock, mult(1,1000)).Times(1);

    objectUnderTest.mult(1000,1);


}
