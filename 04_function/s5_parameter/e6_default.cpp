/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * parameter - default value
 */
#include <iostream>

void sayHello(int count = 1)
{
    std::cout << "...";
    for (int i = 0; i < count; ++i)
    {
        std::cout << " hello";
    }
    std::cout << "!\n";
}

int main()
{
    sayHello(3);
    sayHello();
}
