#pragma once
#include <iostream>
#include <string>
#include "../Cell/Cell.h"
#include "../JumpList/JumpList.h"

class Program {
public:
    Program();
    ~Program();
    void load();
    void execute();

private:
    void executeInstruction(char);
    void checkJumpBackwards();
    void checkJumpForwards();
    void movePointerLeft();
    void movePointerRight();

private:
    bool        error = false;
    JumpList*   jumpList = nullptr;
    std::string instructions;
    const int   CELLS = 300;
    Cell*       cells = nullptr;
    Cell*       currentCell = cells;
    int         programCounter = 0;
};