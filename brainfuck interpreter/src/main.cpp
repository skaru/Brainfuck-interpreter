#include "Program/Program.h"

// TODO:
// Fix ascii input (only numbers possible)

int main() {
    while(true) {
        Program p;
        p.load();
        p.execute();
    }
}
