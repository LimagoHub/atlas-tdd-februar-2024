//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once

#include <string>
class Dependency {

public:
    Dependency() = default;
    virtual ~Dependency()=default;
    virtual bool isSolvent(std::string creditCardNumber) const = 0;

};
