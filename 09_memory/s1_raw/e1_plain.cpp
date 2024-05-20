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

    // some explicitly initialized, the other elements are implicitly initialized to 0
    // when not initialized, no assumption could be done on the element values
    int sData[6]{1, 2, 3};
    std::cout << "An array of int on the stack: ";
    for (int cur : sData)
    {
        std::cout << cur << ' ';
    }
    std::cout << '\n';

    // some explicitly initialized, the other elements are implicitly initialized to 0
    // when not initialized, no assumption could be done on the element values
    int *hData = new int[6]{1, 2, 3};
    std::cout << "An array of int on the heap: ";
    for (int i = 0; i < 6; ++i)
    {
        std::cout << hData[i] << ' ';
    }
    std::cout << '\n';
    delete[] hData;

#ifdef __GNUC__
    // this works for GCC, but it is not standard C++!
    srand(time(nullptr));
    int size = rand() % 10;
#else
    const int size = 5;
#endif
    std::cout << "An array on the stack sized " << size << ": ";

    // all implicitly initialized to 0
    // when not initialized, no assumption could be done on the element values
    double values[size]{};
    for (int i = 0; i < size; ++i)
    {
        std::cout << values[i] << ' ';
    }
    std::cout << '\n';
}
