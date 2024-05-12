// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>

int main() {
    const char* str = "Hello W 17 This is a Teststring 4 6";

    std::cout << "Number of words without digits: " << faStr1(str) << std::endl;
    std::cout << "Number of words starting with uppercase Latin letter: " << faStr2(str) << std::endl;
    std::cout << "Average word length: " << faStr3(str) << std::endl;

    return 0;
}
