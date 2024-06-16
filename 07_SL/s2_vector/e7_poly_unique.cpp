/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * achieving polymorphism by unique smart pointers
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ExtendedEntry.h"

int main()
{
    // initializer_list requires copy, but unique_ptr is not copiable
    std::vector<std::unique_ptr<Entry>> values;

    std::cout << "*** Pushing unique ptrs on the container\n";
    values.push_back(std::make_unique<Entry>(1, "Tom"));
    values.push_back(std::make_unique<Entry>(2, "Bob"));
    values.push_back(std::make_unique<Entry>(3, "Kim"));
    values.push_back(std::make_unique<ExtendedEntry>(4, "Wim", "!!!"));

    std::cout << "*** All entries say hello\n";
    for (const auto &cur : values)
    {
        cur->sayHello();
    }

    std::cout << "*** The container is about to go out of scope\n";
}
