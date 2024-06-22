/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * array
 */
#include <iostream>

int main()
{
    // the size of data is calculated by the compiler
    int data[]{42, 12, 18, 21, 5, 33};
    std::cout << "The first value in data: " << data[0] << '\n';

    constexpr size_t d_size = sizeof(data) / sizeof(int);
    std::cout << "Size of data: " << d_size << '\n';
    std::cout << "The last value in data: " << data[d_size - 1] << '\n';
    std::cout << "This is a dangerous mistake: " << data[d_size] << '\n';

    // the address of the first cell in an array (explicit)
    int *ptr = &data[0];
    std::cout << "First cell in data, address and value: " << ptr << " -> " << *ptr << '\n';

    // the address of the first cell in an array is the address of the entire array
    ptr = data;
    std::cout << "Same: " << ptr << " -> " << *ptr << '\n';

    ptr = &data[d_size - 1];
    std::cout << "Last cell: " << ptr << " -> " << *ptr << '\n';

    int &ref = data[d_size - 1];
    std::cout << "ref and data[" << d_size - 1 << "] " << ref;
    std::cout << ' ' << data[d_size - 1] << '\n';

    ref += 1;
    std::cout << "ref and data cell after increasing ref " << ref << ' ' << data[d_size - 1] << '\n';

    for (size_t i = 0; i < d_size; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';

    ptr = data;
    for (size_t i = 0; i < d_size; ++i)
    {
        std::cout << *(ptr + i) << ' ';
    }
    std::cout << '\n';
}
