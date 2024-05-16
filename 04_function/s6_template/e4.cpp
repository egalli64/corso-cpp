/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * template example - binary search
 */
#include <iostream>

template <typename T> int binarySearch(T data[], int size, T target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int middle = low + (high - low) / 2;

        if (data[middle] == target)
        {
            return middle;
        }
        else if (data[middle] < target)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }

    return -1;
}

void test_1()
{
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 6;
    int sz = sizeof(values) / sizeof(int);

    int result = binarySearch(values, sz, target);
    if (result != -1)
    {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }
}

void test_2()
{
    double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double target = 6.2;
    int sz = sizeof(values) / sizeof(int);

    int result = binarySearch(values, sz, target);
    if (result != -1)
    {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }
}

int main()
{
    test_1();
    test_2();
}
