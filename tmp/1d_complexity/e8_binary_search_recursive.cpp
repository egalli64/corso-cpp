/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * Binary search - recursive
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

int recursive(int values[], int target, int first, int last)
{
    if (first > last)
    {
        return -1;
    }

    int current = first + (last - first) / 2;
    if (values[current] > target)
    {
        return recursive(values, target, first, current - 1);
    }
    else if (values[current] < target)
    {
        return recursive(values, target, current + 1, last);
    }
    else
    {
        return current;
    }
}

int main()
{
    int values[]{3, 6, 10, 15, 19, 22, 27, 34, 36, 42, 45};
    constexpr size_t sz = sizeof(values) / sizeof(int);

    std::cout << "Working on: ";
    print(values, sz);

    int target = 35;
    int pos = recursive(values, target, 0, sz - 1);

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