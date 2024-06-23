/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * function with doxygen style document comment
 */
#include "e2.hpp"
#include <iostream>

/**
 * @brief Invoking a function declared in a header file
 */
int main()
{
    printHello();
}

/**
 * @brief Defining a free function declared in a header file
 */
void printHello()
{
    std::cout << "Hello\n";
}
