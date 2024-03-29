/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * allocating variables on stack and heap
 */
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    char c{'X'};
    std::cout << "A char on the stack: " << c << '\n';

    char *pc = new char{'Y'};
    std::cout << "A char on the heap: " << *pc << '\n';
    delete pc;

    // the other three elements are initialized to 0!
    int sData[6]{1, 2, 3};
    std::cout << "An array of int on the stack: ";
    for (int cur : sData)
    {
        std::cout << cur << ' ';
    }
    std::cout << '\n';

    // the other three elements are initialized to 0!
    int *hData = new int[6]{1, 2, 3};
    std::cout << "An array of int on the heap: ";
    for (int i = 0; i < 6; ++i)
    {
        std::cout << hData[i] << ' ';
    }
    std::cout << '\n';
    delete[] hData;

    // works in GCC, but it is not standard C++!
    srand(time(nullptr));
    int size{rand() % 10};
    std::cout << "An array on the stack sized " << size << ": ";
    double values[size]{};
    for (int i = 0; i < size; ++i)
    {
        std::cout << values[i] << ' ';
    }
    std::cout << '\n';
}
