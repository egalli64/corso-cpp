/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector - adding elements
 */
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values;
    std::cout << "-- empty vector" << '\n';
    std::cout << "Size is " << values.size() << '\n';
    std::cout << "Capacity is " << values.capacity() << '\n';

    std::cout << "-- adding elements" << '\n';
    // inserting in a given position could be very slow - elements on its right should be moved
    values.insert(values.begin(), 12);
    // an initializer list could be provided
    values.insert(values.end(), {18, 27, 51});
    // emplace has the same effect of insert, but could reduce object allocations
    values.emplace(values.begin(), 99);
    // push_back is faster
    values.push_back(2);
    // usually fastest
    values.emplace_back(42);

    std::cout << "Size is " << values.size() << '\n';
    std::cout << "Capacity is " << values.capacity() << '\n';
    std::cout << "First element is " << values.front() << '\n';
    std::cout << "Last element is " << values.back() << '\n';
}
