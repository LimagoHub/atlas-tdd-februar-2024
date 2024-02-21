//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once


class Stapel {
private:
    bool empty = true;
public:

    void push(int value) {
        empty = false;
    }
    bool isEmpty() {
        return empty;
    }

};
