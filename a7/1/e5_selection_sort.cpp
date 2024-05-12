/*
 * Corso C++ a7 - https://github.com/egalli64/corso-cpp/a7
 *
 * Selection sort
 */
#include <iostream>

void print(int *data, size_t size)
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
        int pos = i;
        for (int j = i; j < sz; j++)
        {
            if (values[j] < values[pos])
            {
                pos = j;
            }
        }

        std::cout << "Swap!\n";
        int temp = values[i];
        values[i] = values[pos];
        values[pos] = temp;
    }

    std::cout << "Sorted: ";
    print(values, sz);
}