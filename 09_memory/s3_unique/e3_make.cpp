/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * unique_ptr
 */
#include "../Thing.h"
#include <iostream>
#include <memory>

int main()
{
    std::cout << "Prefer creating unique ptr by make_unique\n";
    std::unique_ptr<int> up = std::make_unique<int>(42);
    if (up)
    {
        std::cout << "Value is " << *up << "\n\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    std::unique_ptr<Thing> upt = std::make_unique<Thing>(42);
    if (upt)
    {
        std::cout << "Thing is " << *upt << "\n\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }
}
