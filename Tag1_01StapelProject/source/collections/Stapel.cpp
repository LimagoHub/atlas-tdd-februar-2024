//
// Created by JoachimWagner on 20.02.2024.
//

#include "Stapel.h"
#include "StapelException.h"
auto Stapel::push(int value) -> void {
    if(isFull()) throw StapelException{"Overflow"};
    data.push_back(value);
}

auto Stapel::pop() -> int {
    if(isEmpty()) throw StapelException{"Underflow"};
    auto result = data.back();
    data.pop_back();
    return result;
}

auto Stapel::isEmpty() -> bool const {
    return data.empty();
}

auto Stapel::isFull() -> bool const {
    return data.size() >= 10;
}

