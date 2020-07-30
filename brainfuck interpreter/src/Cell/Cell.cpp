#include "Cell.h"

void Cell::increment() {
    value++;
}
void Cell::decrement() {
    value--;
}

void Cell::print() {
    std::cout << value;
}

void Cell::getInput() {
    std::cout << "input: ";
    std::cin >> value;
}