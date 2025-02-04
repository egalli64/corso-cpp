/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: unique_ptr, move
 */
#include "../ThingExt.h"
#include <iostream>
#include <memory>

std::unique_ptr<Thing> getUnique()
{
    std::unique_ptr<Thing> up = std::make_unique<ThingExt>(1);
    std::cout << "Returning a unique_ptr: ";
    up->hello();

    // In modern C++ move and copy elision are automatically done by the compiler
    // return std::move(up);

    return up;
}

void passUnique(std::unique_ptr<Thing> up)
{
    std::cout << "A unique_ptr has moved in: ";
    up->hello();

    up.reset(new ThingExt{2});
    std::cout << "Reset for unique_ptr: ";
    up->hello();
}

int main()
{
    std::unique_ptr<Thing> up = getUnique();

    // won't compile
    // passUnique(up);

    passUnique(std::move(up));

    if (!up)
    {
        std::cout << "As expected, the unique smart pointer has no object associated anymore\n";
    }
}
