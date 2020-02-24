#include "JumpList.h"

int JumpList::getNextJumpStart() {
    if(jumps.empty()) {
        throw "Missing matching '['";
    }
    return jumps.begin()->first;
}

int JumpList::getNextJumpEnd() {
    if(jumps.empty()) {
        throw "Missing matching ']'";
    }
    return jumps.begin()->second;
}

void JumpList::addJump(const int startpoint, const std::string instructions) {
    int endpoint;

    if((endpoint = findEndpoint(startpoint, instructions)) != -1) {
        for(auto jump = jumps.begin();jump != jumps.end(); ++jump) {
            if(jump->second == endpoint) {
                throw "Missing matching ']'";
            }
        }
        jumps.emplace_front(startpoint, endpoint);
    } else {
        throw "Missing matching ']'";
    }
}

void JumpList::removeJump() {
    if(jumps.empty()) {
        throw "Missing matching '['";
    }
    jumps.pop_front();

}

int JumpList::findEndpoint(const int offset, const std::string instructions) {
    int jumpCounter = 0;

    for(int i = 1;instructions[i] != '\0'; i++) {
        if(instructions[i] == '[') {
            jumpCounter++;
        } else if(instructions[i] == ']') {
            if(jumpCounter > 0) {
                jumpCounter--;
            } else {
                return offset + i;
            }
        }
    }

    return -1;
}