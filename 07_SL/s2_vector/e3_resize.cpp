/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector - resize
 */
#include <iostream>
#include <vector>

namespace
{
/**
 * @brief a simple template function to print all the elements in an iterval
 *
 * @param it iterator to the first element to be printed
 * @param end iterator to the end sentinel
 * @param label a heading message to be printed
 */
template <typename IT> void print(IT it, IT end, const std::string &label)
{
    std::cout << label << ": ";
    while (it != end)
    {
        std::cout << *it << ' ';
        it += 1;
    }
    std::cout << '\n';
}
} // namespace

int main()
{
    std::vector<int> given{6, 4, 3};
    print(given.begin(), given.end(), "A vector with a few given values");

    given.resize(4);
    print(given.begin(), given.end(), "After resizing (growing, default value for new element)");

    given.resize(2);
    print(given.begin(), given.end(), "After resizing (shrinking)");

    given.resize(4, 2);
    print(given.begin(), given.end(), "After resizing, (growing, given value for new element)");
}
