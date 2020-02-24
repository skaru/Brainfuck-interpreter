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
    bool error = false;
    JumpList *jumpList = new JumpList;
    std::string instructions;
    const int CELLS = 300;
    Cell *cells = new Cell[CELLS];
    Cell *currentCell = &cells[0];
    int programCounter = 0;
};