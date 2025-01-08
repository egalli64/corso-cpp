/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector: achieving polymorphism by smart pointers (unique)
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ExtendedEntry.h"

int main()
{
    std::cout << "*** Unique Smart Pointer Vector\n";
    // unique_ptr is not copiable, as required by initializer_list, so, can't be used here
    std::vector<std::unique_ptr<Entry>> values;

    values.push_back(std::make_unique<Entry>(1, "Tom"));
    values.push_back(std::make_unique<Entry>(2, "Bob"));
    values.push_back(std::make_unique<Entry>(3, "Kim"));
    values.push_back(std::make_unique<ExtendedEntry>(4, "Wim", "!!!"));

    std::cout << "*** All entries say hello\n";
    for (const auto &cur : values)
    {
        cur->sayHello();
    }

    std::cout << "*** Vector is about to going out of scope\n";
}
