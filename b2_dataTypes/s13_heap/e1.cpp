/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * stack / heap
 */
#include <iostream>

int main()
{
    char c = 'x';
    std::cout << "An initialized char on the stack: " << c << '\n';

    char *pc = new char;
    std::cout << "An uninitialized char on the heap: " << static_cast<int>(*pc) << '\n';
    delete pc;

    char *pz = new char{'Z'};
    std::cout << "An initialized char on the heap: " << *pz << '\n';
    delete pz;

    int sData[6]{1, 2, 3};
    std::cout << "First element in an array on the stack: " << sData[0] << '\n';
    std::cout << "Last element in an array on the stack: " << sData[5] << '\n';

    int *hData = new int[6]{1, 2, 3};
    std::cout << "First element in an array on the stack: " << hData[0] << '\n';
    std::cout << "Last element in an array on the stack: " << hData[5] << '\n';
    delete[] hData;
}
