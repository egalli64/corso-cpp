/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * function with doxygen style document comment
 */
#include <iostream>

/**
 * @brief Declaring a free function
 */
void printHello();

/**
 * @brief Defining a minimal free function
 */
void empty() {}

/**
 * @brief Defining the main function
 *
 * @return int resulting status of the program, zero for success
 */
int main()
{
    // invoking functions
    printHello();
    empty();
}

/**
 * @brief Defining a free function
 */
void printHello()
{
    std::cout << "Hello\n";
}
