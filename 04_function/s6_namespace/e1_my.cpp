/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * my namespace with a function in it
 */
#include "e1.hpp"
#include <iostream>

namespace my
{
/**
 * @brief Defining a free function in a namespace
 */
void hello()
{
    std::cout << "Hello\n";
}
} // namespace my

// using namespace my;

int main()
{
    // require a using directive for the my namespace to compile
    // hello();

    my::hello();
}
