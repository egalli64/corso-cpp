/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm exercises (w/ solution)
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

namespace
{
template <typename T> void print(const std::vector<T> &items, const std::string &label)
{
    std::cout << label << ": [ ";
    for (const auto &item : items)
    {
        std::cout << item << ' ';
    }
    std::cout << "]\n";
}

} // namespace

int main()
{
    std::vector<int> data{2, 5, 6, 3, 4, 1};
    std::vector<std::string> strings{"alpha", "beta", "gamma", "delta", "eta"};

    print(data, "Original data");
    print(strings, "Original strings");

    // 1. create a new vector containing the squared values of the original vector

    // inplace
    // std::for_each(data.begin(), data.end(), [](int& x) { x *= x; });

    std::vector<int> squared;
    std::transform(data.begin(), data.end(), std::back_inserter(squared), [](int n) { return n * n; });
    print(squared, "Squared data");

    // 2. sort a vector of strings by size (natural)
    std::sort(strings.begin(), strings.end(),
              [](const std::string &a, const std::string &b) { return a.size() < b.size(); });
    print(strings, "Strings sorted by size");

    // 3. sum of the squared values
    int sum = std::accumulate(squared.begin(), squared.end(), 0);
    std::cout << "Sum of squares: " << sum << '\n';

    // 3b. product of squared values
    int prod = std::accumulate(squared.begin(), squared.end(), 1, [](int acc, int cur) { return acc * cur; });
    std::cout << "Product of squares: " << prod << '\n';

    // 4. count the strings longer than 4
    int count = std::count_if(strings.begin(), strings.end(), [](const std::string &s) { return s.size() > 4; });
    std::cout << "Long strings: " << count << '\n';

    // 5a. find the first string sized 4
    auto it = std::find_if(strings.begin(), strings.end(), [](const std::string &s) { return s.size() == 4; });
    std::cout << "Found: " << (it == strings.end() ? "None" : *it) << '\n';

    // 5b. sized 6
    it = std::find_if(strings.begin(), strings.end(), [](const std::string &s) { return s.size() == 6; });
    std::cout << "Found: " << (it == strings.end() ? "None" : *it) << '\n';

    // 6. is there a 'g' string?
    bool hasG = std::any_of(strings.begin(), strings.end(),
                            [](const std::string &s) { return s.find('g') != std::string::npos; });
    std::cout << "Is there a 'g' in at least a string? " << (hasG ? "Yes" : "No") << '\n';

    // 7. replace the odd values in data with 0
    std::replace_if(
        data.begin(), data.end(), [](int x) { return x % 2 == 1; }, 0);
    print(data, "No odd");

    // 8. check if all the values in data are non negative
    bool allEven = std::all_of(data.begin(), data.end(), [](int x) { return x % 2 == 0; });
    std::cout << "All data even? " << (allEven ? "Yes" : "No") << '\n';

    // 9. add the element in the same position in data and squared and put that values in a new vector
    std::vector<int> merged;
    std::transform(data.begin(), data.end(), squared.begin(), std::back_inserter(merged),
                   [](int lhs, int rhs) { return lhs + rhs; });
    print(merged, "Merged");

    // 10. copy the even values in vector (9) in a new vector
    std::vector<int> evens;
    std::copy_if(merged.begin(), merged.end(), std::back_inserter(evens), [](int x) { return x % 2 == 0; });
    print(evens, "Even numbers");

    // 11. print the vector (10) in reversed order
    std::cout << "Reversed order: ";
    for (auto it = evens.rbegin(); it != evens.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    // 12. calculate and put in a new vector the partial sum of the elements in (9)
    std::vector<int> ps;
    std::partial_sum(merged.begin(), merged.end(), std::back_inserter(ps));
    print(ps, "Partial sum");
}