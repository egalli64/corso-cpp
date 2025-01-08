/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: unique_ptr, reset
 */
#include "../Thing.h"
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<Thing> sp = std::make_unique<Thing>(1);

    std::cout << "Resetting\n";
    sp.reset(new Thing{2});

    std::cout << "Resetting to nullptr: ";
    sp.reset();

    std::cout << "Resetting on an empty unique ptr: ";
    sp.reset(new Thing{3});

    std::cout << "Resetting to nullptr by assignment: ";
    sp = nullptr;
}
