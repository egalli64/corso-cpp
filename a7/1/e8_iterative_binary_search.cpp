/*
 * Corso C++ a7 - https://github.com/egalli64/corso-cpp/a7
 *
 * Binary search - iterative
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

int iterative(int values[], int sz, int target)
{
    int first = 0;
    int last = sz - 1;

    while (first <= last)
    {
        int current = first + (last - first) / 2;
        if (values[current] > target)
        {
            last = current - 1;
        }
        else if (values[current] < target)
        {
            first = current + 1;
        }
        else
        {
            return current;
        }
    }

    return -1;
}

int main()
{
    int values[]{3, 6, 10, 15, 19, 22, 27, 34, 36, 42, 45};
    constexpr size_t sz = sizeof(values) / sizeof(int);

    std::cout << "Working on: ";
    print(values, sz);

    int target = 35;
    int pos = iterative(values, sz, target);

    std::cout << "Target " << target;
    if (pos == -1)
    {
        std::cout << " not found\n";
    }
    else
    {
        std::cout << " found at position " << pos << '\n';
    }
}