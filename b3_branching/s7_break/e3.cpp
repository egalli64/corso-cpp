/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * break in a do while
 */
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    srand(time(nullptr));

    do
    {
        int aRandomValue = rand() % 100; // [0..99]
        std::cout << aRandomValue << ' ';

        if (aRandomValue > 66)
        {
            break;
        }
    } while (true);

    std::cout << "Done!\n";
}
