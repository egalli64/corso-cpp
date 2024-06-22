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

    constexpr size_t d_size = 6;
    int s_data[d_size]{1, 2, 3};
    std::cout << "An array on the stack: ";
    for (size_t i = 0; i < d_size; ++i)
    {
        std::cout << s_data[i] << ' ';
    }
    std::cout << '\n';

    int *h_data = new int[d_size]{1, 2, 3};
    std::cout << "AN array on the heap: ";
    for (size_t i = 0; i < d_size; ++i)
    {
        std::cout << h_data[i] << ' ';
    }
    std::cout << '\n';

    delete[] h_data;
}
