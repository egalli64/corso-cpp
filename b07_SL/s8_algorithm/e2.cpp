/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: replace
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<int> &items, const std::string &label)
{
    std::cout << label << " [ ";
    for (const auto &item : items)
    {
        std::cout << item << ' ';
    }
    std::cout << "]\n";
}

// it is not difficult to create own "algorithm" similar to the standard ones
// here, an in-place modifier that squares each value in an interval
template <typename IT>
void square(IT first, IT last)
{
    while (first != last)
    {
        *first = (*first) * (*first);
        ++first;
    }
}

int main()
{
    std::vector<int> values{7, 3, 11};
    print(values, "A vector");

    std::replace(values.begin(), values.end(), 3, 5);
    print(values, "Replaced");

    square(values.begin(), values.end());
    print(values, "Squared");
}
