//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once

#include "gmock/gmock.h"
#include "MockDependency.h"
#include "../source/MyServiceUsingDependency.h"

using namespace testing;

class MyServiceUsingDependencyTest : public Test{

protected:
    MockDependency dependencyMock;
    MyServiceUsingDependency objectUnderTest{dependencyMock};


};
