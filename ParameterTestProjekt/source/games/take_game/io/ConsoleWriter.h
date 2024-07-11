//
// Created by JoachimWagner on 10.07.2024.
//

#pragma once


#include <iostream>
#include "Writer.h"

class ConsoleWriter : public Writer{
public:
    void write(const std::string &message) const override {
        std::cout << message << std::endl;
    }
};
