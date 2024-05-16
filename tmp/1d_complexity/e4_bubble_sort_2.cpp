/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * Bubble sort (2) - reduced internal loop
 */
#include <iostream>

void print(int data[], size_t size)
{
    std::cout << "[ ";
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << "]\n";
}

int main()
{
    int values[]{6, 1, 3, 7, 4, 5, 2, 8};
    constexpr size_t sz = sizeof(values) / sizeof(int);

    std::cout << "Working on: ";
    print(values, sz);

    for (int i = 0; i < sz - 1; i++)
    {
        std::cout << "External loop " << i << '\n';
        for (int j = 0; j < sz - i - 1; j++)
        {
            std::cout << "Internal loop " << j << '\n';
            if (values[j] > values[j + 1])
            {
                std::cout << "Swap!\n";
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }

    std::cout << "Sorted: ";
    print(values, sz);
}