//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once
#include "gmock/gmock.h"
#include "../source/math/Multiplizierer.h"


class MockMultiplizierer : public Multiplizierer {
public:
    MOCK_METHOD(unsigned long, mult, (unsigned a, unsigned b), (const, override));
};
