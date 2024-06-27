/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * dynamic_cast vs reinterpret_cast - on pointers
 */
#include "Derived.hpp"
#include "Other.hpp"
#include <iostream>

int main()
{
    Derived d = Derived();
    Base &base = d;
    Other other;

    Derived *downcast = dynamic_cast<Derived *>(&base);
    if (downcast != nullptr)
    {
        downcast->f();
    }
    else
    {
        std::cout << "Unexpected\n";
    }

    // warning: dynamic_cast can never succeed
    Derived *wrong = dynamic_cast<Derived *>(&other);
    if (wrong != nullptr)
    {
        std::cout << "Unexpected\n";
    }
    else
    {
        std::cout << "dynamic_cast failed\n";
    }

    // no check, whatever happens is on the coder
    wrong = reinterpret_cast<Derived *>(&other);
    std::cout << "undefined behavior: ";
    wrong->f();
}