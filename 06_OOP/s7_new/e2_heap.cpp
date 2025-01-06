/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: object creation / deletion on the heap
 */
#include <iostream>
#include <memory>

#include "Player.hpp"

int main()
{
    Player *p2 = new Player(2, 203.45);
    p2->increaseScore(23.3);
    std::cout << p2->id() << ' ' << p2->score() << '\n';
    delete p2;
}
