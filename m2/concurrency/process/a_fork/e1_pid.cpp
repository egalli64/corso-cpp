/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 */
#include <iostream>
#include <unistd.h>

int main()
{
    std::cout << "This process ID: " << getpid() << '\n';
    std::cout << "The parent process ID: " << getppid() << '\n';
}
