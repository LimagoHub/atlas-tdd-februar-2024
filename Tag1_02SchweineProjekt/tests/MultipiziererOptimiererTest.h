//
// Created by JoachimWagner on 21.02.2024.
//

#pragma once

#include "gmock/gmock.h"
#include "MockMultiplizierer.h"
#include "../source/math/MultipiziererOptimierer.h"


using namespace testing;

class MultipiziererOptimiererTest :public Test{
protected:

    MockMultiplizierer multipliziererMock;
    MultipiziererOptimierer objectUnderTest{multipliziererMock};

};
