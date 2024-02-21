//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include <iostream>
#include <memory>
#include <string>


class computer_player {

   


public:


    unsigned do_turn(const unsigned &stones) const  {

        const int moves[] = {3,1,1,2};
        int move = moves[stones % 4];
        std::cout << "Computer nimmt " + std::to_string(move) + " Steine." << std::endl;

        return move;
    }
};




