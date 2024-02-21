//
// Created by JoachimWagner on 21.02.2024.
//

#pragma once
#include "gmock/gmock.h"
#include "../Mockpersonen_repository.h"
#include "../../source/services/personen_service_impl.h"
#include "../../source/services/personen_service_exception.h"

using namespace testing;

class personen_service_impl_test:public Test {
protected:
    Mockpersonen_repository repositoryMock;
    personen_service_impl objectUnderTest{repositoryMock};
};
