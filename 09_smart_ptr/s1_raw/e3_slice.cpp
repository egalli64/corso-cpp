/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Beware of slicing!
 */
#include "../ThingExt.h"
#include <iostream>
#include <memory>

/**
 * @brief a function showing the slice problem
 */
void slice()
{
    std::cout << "The slicing problem\n";

    ThingExt te{1};
    std::cout << "Original hello: ";
    te.hello();

    Thing t{te};
    std::cout << "Sliced hello: ";
    t.hello();
}

/**
 * @brief no slice when working with pointers
 */
void no_slice()
{
    std::cout << "Solving the slicing problem\n";

    Thing *pt = new ThingExt{2};
    std::cout << "Full hello: ";
    pt->hello();
    delete pt;
}

int main()
{
    slice();
    no_slice();
}
