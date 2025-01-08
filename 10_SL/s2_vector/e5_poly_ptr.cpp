/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector: achieving polymorphism by pointers
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ExtendedEntry.h"

int main()
{
    std::cout << "Raw Pointer Vector\n";
    std::vector<Entry *> values{new Entry(1, "Tom"), new Entry(2, "Bob")};
    values.push_back(new Entry(3, "Kim"));
    values.push_back(new ExtendedEntry(4, "Wim", "!!!"));
    for (const Entry *cur : values)
    {
        cur->sayHello();
    }
    std::cout << "Access to an element in vector: ";
    values[0]->sayHello();

    ExtendedEntry *ee = dynamic_cast<ExtendedEntry *>(values[values.size() - 1]);
    if (ee)
    {
        std::cout << "Last element is extended: " << *ee << '\n';
    }
    else
    {
        std::cout << "You should not see this line" << '\n';
    }

    std::cout << "Before vector goes out of scope, a handmade cleanup is required!\n";
    for (Entry *cur : values)
    {
        delete cur;
    }

    // a clear is not actually required here, the vector is about to be destroyed
    std::cout << "Size is still " << values.size() << '\n';
    values.clear();
    std::cout << "Now size is " << values.size() << '\n';
}
