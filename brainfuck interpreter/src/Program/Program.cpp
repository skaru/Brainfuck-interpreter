#include "Program.h"

Program::Program() : cells(new Cell[CELLS]), jumpList(new JumpList) 
{}

Program::~Program() {
    delete[] cells;
    delete jumpList;
    std::cout << '\n';
}

void Program::load() {
    std::cout << "$";
    std::cin >> instructions;
    instructions.push_back('\0');
}

void Program::execute() {
    for(;instructions[programCounter] != '\0'; programCounter++) {
        try {
            executeInstruction(instructions[programCounter]);
        } catch(const char *msg) {
            std::cout << "Error at instruction " << programCounter + 1 << ": " << msg << "\n";
            break;
        }
        catch ( ... ) {
            std::cout << "Unexpected error\n";
        }
    }
}

void Program::executeInstruction(char instruction) {
    switch(instruction) {
        case '+':
            currentCell->increment();
            break;
        case '-':
            currentCell->decrement();
            break;
        case '<':
            movePointerLeft();
            break;
        case '>':
            movePointerRight();
            break;
        case '.':
            currentCell->print();
            break;
        case ',':
            currentCell->getInput();
            break;
        case '[':
            checkJumpForwards();
            break;
        case ']':
            checkJumpBackwards();
            break;
        default:
            throw "unexpected character";
    }
}

void Program::checkJumpForwards() {
    jumpList->addJump(programCounter, &instructions[programCounter]);

    if(!currentCell->value) {
        programCounter = jumpList->getNextJumpEnd();
        jumpList->removeJump();
    }
}

void Program::checkJumpBackwards() {
    if(!currentCell->value)
        jumpList->removeJump();
    else
        programCounter = jumpList->getNextJumpStart();
}

void Program::movePointerLeft() {
    if(currentCell > &cells[0])
        currentCell--;
    else throw "out of bounds(-1)";
}

void Program::movePointerRight() {
    if(currentCell < &cells[CELLS - 1])
        currentCell++;
    else throw "out of bounds(+1)";
}