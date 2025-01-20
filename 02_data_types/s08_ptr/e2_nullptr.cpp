/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * nullptr
 */
#include <iostream>

int main()
{
    std::cout << "Null pointer\n\n";

    int *ptr = nullptr;
    std::cout << "An unused pointer: " << ptr << '\n';
    std::cout << "A null pointer can't be dereferenced ... " << '\n';
    // Runtime problem: segmentation fault
    // std::cout << *ptr << '\n';
}
