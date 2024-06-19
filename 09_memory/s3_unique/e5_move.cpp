/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * unique_ptr
 */
#include "../ThingExt.h"
#include <iostream>
#include <memory>

namespace
{
/**
 * @brief make a ThingExt unique_ptr by id
 *
 * @param id the Thing id
 * @return the generated ThingExt as a Thing unique ptr
 */
std::unique_ptr<Thing> make_unique_thing(int id)
{
    std::cout << "*** make_unique_thing() for " << id << '\n';
    std::unique_ptr<Thing> up = std::make_unique<ThingExt>(id);
    up->hello();

    std::cout << "*** Returning a unique_ptr\n";

    // In modern C++ move and copy elision are automatically done by the compiler
    // return std::move(up);
    return up;
}

/**
 * @brief Print and reset the unique ptr passed in
 *
 * @param up a unique ptr - should be moved
 */
void pass_unique(std::unique_ptr<Thing> up)
{
    std::cout << "*** A unique_ptr has moved in pass_unique(): " << *up << '\n';

    up.reset(new ThingExt{3});
    std::cout << "*** After reset: " << *up << '\n';
}
} // namespace

int main()
{
    // the object received by copy elision is passed to the unique_ptr ctor
    std::unique_ptr<Thing> up = make_unique_thing(1);
    std::cout << "*** up is " << *up << '\n';

    std::unique_ptr<Thing> up2;
    // the object received by copy elision is passed to the unique_ptr assignment operator
    up2 = make_unique_thing(2);
    std::cout << "*** up2 is " << *up2 << '\n';

    // won't compile
    // pass_unique(up);

    pass_unique(std::move(up));

    if (!up)
    {
        std::cout << "*** As expected, the moved unique smart pointer has no object associated anymore\n";
    }
}
