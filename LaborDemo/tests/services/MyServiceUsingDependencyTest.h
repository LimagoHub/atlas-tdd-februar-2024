//
// Created by JoachimWagner on 11.07.2024.
//

#pragma once
#pragma once
#include "gmock/gmock.h"
#include "MockDependency.h"
#include "../../source/services/MyServiceUsingDependency.h"
using namespace testing;

class MyServiceUsingDependencyTest: public Test {
protected:
    MockDependency dependencyMock;
    MyServiceUsingDependency objectUnderTest{dependencyMock};

    void SetUp() override;
};
