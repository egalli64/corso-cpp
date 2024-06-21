/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * achieving polymorphism by shared smart pointers
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ExtendedEntry.h"

int main()
{
    std::cout << "*** Initializing the container with a list of share ptrs\n";
    std::vector<std::shared_ptr<Entry>> values{std::make_shared<Entry>(1, "Tom"), std::make_shared<Entry>(2, "Bob")};
    std::cout << "*** Pushing shared ptrs on the container\n";
    values.push_back(std::make_shared<Entry>(3, "Kim"));
    values.push_back(std::make_shared<ExtendedEntry>(4, "Wim", "!!!"));

    std::cout << "*** All entries say hello (by ref)\n";
    for (const auto &cur : values)
    {
        std::cout << "Use count is " << cur.use_count() << " ... ";
        cur->sayHello();
    }

    std::cout << "*** All entries say hello (by copy)\n";
    for (auto cur : values)
    {
        std::cout << "Use count is " << cur.use_count() << " ... ";
        cur->sayHello();
    }

    std::cout << "*** The container is about to go out of scope\n";
}
