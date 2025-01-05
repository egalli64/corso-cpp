/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * no polymorphism on statically typed vector!
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ExtendedEntry.h"

int main()
{
    std::cout << "Statically typed vector - no polymorphism!\n";
    std::vector<Entry> values{{1, "Tom"}, {2, "Bob"}};

    std::cout << "*** values: ";
    for (const Entry &cur : values)
    {
        std::cout << cur << ' ';
    }
    std::cout << '\n';

    // the vector should grow, elements are moved to the new array
    std::cout << "*** Kim is pushed back into the vector\n";
    values.push_back({3, "Kim"});
    std::cout << "*** Obi is emplaced into the vector\n";
    values.emplace_back(4, "Obi");

    std::cout << "*** Wim is defined and then says hello\n";

    {
        ExtendedEntry wim{5, "Wim", "!!!"};
        wim.sayHello();

        // BAD! Wim is sliced off !!!
        std::cout << "*** Wim is pushed back into the vector\n";
        values.push_back(wim);

        std::cout << "*** The original Wim is about to go out of scope\n";
    }

    std::cout << "*** Everyone say hello (as Entry!)\n";
    for (const Entry &cur : values)
    {
        cur.sayHello();
    }

    ExtendedEntry *ee = dynamic_cast<ExtendedEntry *>(&values[4]);
    if (ee == nullptr)
    {
        std::cout << "*** Wim is not seen as an ExtendedEntry anymore!\n";
    }
    else
    {
        std::cout << "You should not see this line\n";
    }

    std::cout << "*** values is about to go out of scope\n";
}
