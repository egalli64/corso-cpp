/*
 * Corso C++ - https://github.com/egalli64/corso-cpp/a7
 *
 * Bubble sort (3) - stop looping when no swap detected
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
    // a random example
    // int values[]{6, 1, 3, 7, 4, 5, 2, 8};

    // check it on an almost-sorted array
    int values[]{6, 1, 2, 3, 4, 5, 7, 8};
    constexpr size_t sz = sizeof(values) / sizeof(int);

    std::cout << "Working on: ";
    print(values, sz);

    for (int i = 0; i < sz - 1; i++)
    {
        std::cout << "External loop " << i << '\n';
        bool swapped = false;
        for (int j = 0; j < sz - i - 1; j++)
        {
            std::cout << "Internal loop " << j << '\n';
            if (values[j] > values[j + 1])
            {
                std::cout << "Swap!\n";
                swapped = true;

                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }

        if (!swapped)
        {
            break;
        }
    }

    std::cout << "Sorted: ";
    print(values, sz);
}