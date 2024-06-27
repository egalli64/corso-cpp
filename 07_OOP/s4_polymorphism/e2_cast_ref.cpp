/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * dynamic_cast vs reinterpret_cast - on references
 */
#include "Derived.hpp"
#include "Other.hpp"
#include <iostream>

int main()
{
    Derived d = Derived();
    Base &base = d;
    Other other;

    try
    {
        Derived &downcast = dynamic_cast<Derived &>(base);
        downcast.f();
    }
    catch (const std::bad_cast &ex)
    {
        std::cout << "Unexpected\n";
    }

    try
    {
        Derived &wrong = dynamic_cast<Derived &>(other);
        wrong.f();
    }
    catch (const std::bad_cast &ex)
    {
        std::cout << ex.what() << " from an Other object to a Derived reference\n";
    }

    // no check, whatever happens is on the coder
    Derived &wrong = reinterpret_cast<Derived &>(other);
    wrong.f();
}
