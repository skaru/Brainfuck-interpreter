#include <iostream>
#include "Program/Program.h"

// TODO:
// Fix ascii input (only numbers possible)

int main() {
    while(true) {
        std::unique_ptr<Program> program(new Program);
        program->load();
        program->execute();
    }
}
