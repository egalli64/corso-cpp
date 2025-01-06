/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: object creation / deletion on the stack
 */
#include <iostream>
#include <memory>

#include "Player.hpp"

int main()
{
    Player p1{1, 102.12};
    p1.increaseScore(12.21);
    std::cout << p1.id() << ' ' << p1.score() << '\n';
}
