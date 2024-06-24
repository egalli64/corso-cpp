/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * template example - binary search
 */
#include <iostream>

namespace
{
/**
 * @brief binary search as template function
 *
 * @param data the T array to be searched
 * @param size the data array
 * @param target the searched value
 * @return the index of the first occurrence of target or -1 if not found
 */
template <typename T> int binary_search(T data[], int size, T target)
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

/**
 * @brief smoke test, int array, target should be found
 */
void test_1()
{
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 6;
    int sz = sizeof(values) / sizeof(int);

    int result = binary_search(values, sz, target);
    if (result != -1)
    {
        std::cout << "Element found at index " << result << '\n';
    }
    else
    {
        std::cout << "Unexpected\n";
    }
}

/**
 * @brief smoke test, double array, target should not be found
 */
void test_2()
{
    double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double target = 6.2;
    int sz = sizeof(values) / sizeof(double);

    int result = binary_search(values, sz, target);
    if (result != -1)
    {
        std::cout << "Unexpected\n";
    }
    else
    {
        std::cout << "Element not found\n";
    }
}
} // namespace

int main()
{
    test_1();
    test_2();
}
