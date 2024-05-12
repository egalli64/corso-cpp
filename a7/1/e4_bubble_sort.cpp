/*
 * Corso C++ a7 - https://github.com/egalli64/corso-cpp/a7
 *
 * Bubble sort - basic algorithm
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
    int values[]{6, 1, 3, 4, 5, 2};
    constexpr size_t sz = sizeof(values) / sizeof(int);

    std::cout << "Working on: ";
    print(values, sz);

    for (int i = 0; i < sz - 1; i++)
    {
        std::cout << "Iteration " << i << '\n';
        for (int j = 0; j < sz - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                std::cout << "Swapping on " << j << '\n';
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }

    std::cout << "Sorted: ";
    print(values, sz);
}