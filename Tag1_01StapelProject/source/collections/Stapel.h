//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once
#include <vector>

class Stapel {

    std::vector<int> data;
public:
    Stapel()  = default;
    auto push(int value)->void;
    auto pop()->int;

    auto isEmpty()->bool const;
    auto isFull()->bool const;
};
