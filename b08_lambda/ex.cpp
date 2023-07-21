/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Examples
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> numbers = {1, 3, 5, 4, 2};

    int multi = std::accumulate(numbers.begin(), numbers.end(), 1, [](int acc, int cur) { return acc * cur; });
    std::cout << multi << '\n';

    auto maxIt = std::max_element(numbers.begin(), numbers.end(), [](int a, int b) { return a < b; });
    std::cout << *maxIt << '\n';

    int count = std::count_if(numbers.begin(), numbers.end(), [](int num) { return num % 2 == 0; });
    std::cout << count << '\n';
}