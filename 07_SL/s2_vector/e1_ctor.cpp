/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector - basic methods
 */
#include <iostream>
#include <string>
#include <vector>

namespace
{
/**
 * @brief a simple template function to print all the elements of the passed vector
 *
 * @param values the vector to be printed
 * @param label a heading message to be printed
 *
 * @note a more flexible implementation would be based on iterators
 */
template <typename T> void print(const std::vector<T> &values, const std::string &label)
{
    std::cout << label << ": ";
    for (const T &value : values)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
} // namespace

int main()
{
    // default ctor
    std::vector<int> empty;
    std::cout << "Size of an empty vector is " << empty.size() << '\n';

    std::vector<int> anotherEmpty{};
    std::cout << "Size of another empty vector is " << empty.size() << '\n';

    // initializer list ctor
    std::vector<int> given{6, 4};
    print(given, "A vector with two given values");

    // the uniform initializer would generate a single-element initializer list!
    std::vector<int> v(3);
    print(v, "A vector with default initialized elements");

    // the uniform initializer would generate a two-element initializer list!
    std::vector<int> filled(5, -1);
    print(filled, "A vector filled with a given value");

    std::vector<std::string> sv{"hello", "goodbye"};
    print(sv, "A string vector");

    // increase all the elements
    for (int &cur : given)
    {
        cur += 1;
    }
    print(given, "Increased values");
}
