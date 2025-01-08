/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector: achieving polymorphism by smart pointers (shared)
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ExtendedEntry.h"

int main()
{
    std::cout << "*** Shared Smart Pointer Vector\n";
    std::vector<std::shared_ptr<Entry>> values{std::make_shared<Entry>(1, "Tom"), std::make_shared<Entry>(2, "Bob")};
    values.push_back(std::make_shared<Entry>(3, "Kim"));
    values.push_back(std::make_shared<ExtendedEntry>(4, "Wim", "!!!"));

    std::cout << "*** All entries say hello\n";
    for (const auto &cur : values)
    {
        std::cout << "Use count is " << cur.use_count() << " ... ";
        cur->sayHello();
    }

    for (auto cur : values)
    {
        std::cout << "Use count is " << cur.use_count() << " ... ";
        cur->sayHello();
    }

    std::cout << "*** Vector is about to going out of scope\n";
}
