/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: unique_ptr
 */
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> upEmpty;
    if (!upEmpty)
    {
        std::cout << "The current unique ptr is empty\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    // The factory function make_unique is preferred!
    std::unique_ptr<int> up(new int{42});
    if (up)
    {
        std::cout << "The current unique ptr is _not_ empty\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }
}
