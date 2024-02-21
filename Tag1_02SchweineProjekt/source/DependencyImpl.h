//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once
#include "Dependency.h"

class DependencyImpl :public Dependency{

public:


    bool isSolvent(std::string creditCardNumber) const override;


};
