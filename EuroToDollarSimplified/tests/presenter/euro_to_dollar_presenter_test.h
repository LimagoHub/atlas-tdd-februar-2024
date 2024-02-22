//
// Created by JoachimWagner on 22.02.2024.
//

#pragma once
#include "gmock/gmock.h"
#include "../../source/presenter/euro_to_dollar_presenter_impl.h"
#include "../Mockeuro_to_dollar_calculator.h"
#include "../Mockeuro_to_dollar_view.h"

using namespace testing;


class euro_to_dollar_presenter_test: public Test {
protected:
    Mockeuro_to_dollar_calculator calculatorMock;
    Mockeuro_to_dollar_view viewMock;
    euro_to_dollar_presenter_impl objectUnderTest;

    void SetUp() override;
};
