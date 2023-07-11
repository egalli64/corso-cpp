/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * No SL Array: the raw array
 */
#include <iostream>

void print(int *data, size_t size)
{
    std::cout << "Printing the content of an int array sized " << size << ": ";
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int values[]{6, 4, 3, 6};
    constexpr size_t sz = sizeof(values) / sizeof(int);
    print(values, sz);

    constexpr size_t szh = 3;
    int *hValues = new int[szh]{32, 12, 38};
    print(hValues, szh);
    delete[] hValues;
}
