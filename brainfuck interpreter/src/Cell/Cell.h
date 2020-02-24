#pragma once
#include <iostream>

class Cell {
    public:
    void increment();
    void decrement();
    void print();
    void getInput();
    unsigned char value = 0;
};