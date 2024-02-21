//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once

#include "Dependency.h"
class MyServiceUsingDependency {

    Dependency &dependency; // Inversion of Control,Dependency Injection

public:

    explicit MyServiceUsingDependency(Dependency &dependency) : dependency(dependency) {}

    int bar() {
        if(dependency.isSolvent("Hallo"))
            return 100;
        else
            return -100;
    }
};
