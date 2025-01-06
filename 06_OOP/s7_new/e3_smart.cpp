/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: object creation / deletion
 */
#include <iostream>
#include <memory>

#include "Player.hpp"

int main()
{
    std::unique_ptr<Player> p3 = std::make_unique<Player>(3, 45.3);
    p3->increaseScore(23.3);
    std::cout << p3->id() << ' ' << p3->score() << '\n';
}
