//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once

#include "Multiplizierer.h"
class MultipiziererOptimierer:public Multiplizierer {

    Multiplizierer &multiplizierer;

public:
    explicit MultipiziererOptimierer(Multiplizierer &multiplizierer) : multiplizierer(multiplizierer) {}

    unsigned long mult(unsigned int a, unsigned int b) const override {
        if(a <b )
            return multiplizierer.mult(a,b);

        return multiplizierer.mult(b,a);
    }

};
