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

void test_int()
{
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 6;
    int sz = sizeof(values) / sizeof(int);

    std::cout << "Search of " << target << " gives: " << binarySearch(values, sz, target) << '\n';
}

void test_double()
{
    double values[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    double target = 6.6;
    int sz = sizeof(values) / sizeof(double);

    std::cout << "Search of " << target << " gives: " << binarySearch(values, sz, target) << '\n';
}

void test_string()
{
    std::string values[]{"A.1", "B.2", "C.3", "D.4", "E.5", "F.6", "G.7", "H.8", "I.9"};
    std::string target = "F.6";
    int sz = sizeof(values) / sizeof(std::string);

    std::cout << "Search of " << target << " gives: " << binarySearch(values, sz, target) << '\n';
}

int main()
{
    test_int();
    test_double();
    test_string();
}
