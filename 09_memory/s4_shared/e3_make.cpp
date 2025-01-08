/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: shared_ptr
 */
#include "../Thing.h"
#include <iostream>
#include <memory>

int main()
{
    std::cout << "Prefer creating shared ptr by make_shared\n";
    std::shared_ptr<int> sp = std::make_shared<int>(42);
    if (sp)
    {
        std::cout << "Value is " << *sp << "\n\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    std::shared_ptr<Thing> spt = std::make_shared<Thing>(42);
    if (spt)
    {
        std::cout << "Thing is " << *spt << "\n\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }
}
