//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once
#include "gmock/gmock.h"
#include "../source/Dependency.h"


class MockDependency : public Dependency {
public:
    MOCK_METHOD(bool, isSolvent, (std::string creditCardNumber), (const, override));
};
