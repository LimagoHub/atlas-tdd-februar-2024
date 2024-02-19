//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include <iostream>
#include <memory>
#include "../io/Writer.h"

class computer_player {

    std::unique_ptr<Writer> writer;
public:
    explicit computer_player(std::unique_ptr<Writer> writer) : writer(std::move(writer)) {}

public:


    unsigned do_turn(const unsigned &stones) const  {

        const int moves[] = {3,1,1,2};
        int move = moves[stones % 4];
        writer->write("Computer nimmt " + std::to_string(move) + " Steine.");

        return move;
    }
};




