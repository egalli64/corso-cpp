/*
 * Corso C++ a7 - https://github.com/egalli64/corso-cpp/a7
 *
 * Bubble sort (4) - aggressive cut off
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

    int len = sz - 1;
    for (int i = 0; i < sz - 1; i++)
    {
        std::cout << "External loop " << i << '\n';
        int lastSwap = 0;
        for (int j = 0; j < sz - i - 1; j++)
        {
            std::cout << "Internal loop " << j << '\n';
            if (values[j] > values[j + 1])
            {
                std::cout << "Swap!\n";
                lastSwap = j;

                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }

        if (lastSwap == 0)
        {
            break;
        }
        else
        {
            len = lastSwap;
        }
    }

    std::cout << "Sorted: ";
    print(values, sz);
}