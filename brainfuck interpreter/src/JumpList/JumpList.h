#pragma once
#include <forward_list>
#include <string>

class JumpList {
    public:
    int getNextJumpStart();
    int getNextJumpEnd();
    void addJump(const int, const std::string);
    void removeJump();

    private:
    int findEndpoint(const int, const std::string);
    std::forward_list<std::pair<int, int>> jumps;
};