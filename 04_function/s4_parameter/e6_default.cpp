/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * default argument
 */
#include <iostream>

namespace
{
/**
 * @brief a simple function with a parameter that could be defaulted
 *
 * @param count when an argument is not passed, its value is 1
 */
void sayHello(int count = 1)
{
    std::cout << "...";
    for (int i = 0; i < count; ++i)
    {
        std::cout << " hello";
    }
    std::cout << "!\n";
}
} // namespace

int main()
{
    sayHello(3);
    sayHello();
}
