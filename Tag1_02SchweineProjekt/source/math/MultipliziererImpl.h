//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once

#include <algorithm>
#include "Multiplizierer.h"

class MultipliziererImpl : public Multiplizierer{
public:
    unsigned long mult(unsigned int a, unsigned int b) override {
        unsigned long result = 0UL;


        for (unsigned int i = 0; i < a; ++i) {
            result += b;
        }
        return result;
    }
};
