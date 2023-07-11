/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector - resize
 */
#include <iostream>
#include <vector>

template <typename T> void print(const std::vector<T> &values, const std::string &label)
{
    std::cout << label << ": ";
    for (const T &value : values)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> given{6, 4, 3};
    print(given, "A vector with a few given values");

    given.resize(4);
    print(given, "After resizing (growing)");

    given.resize(2);
    print(given, "After resizing (shrinking)");

    given.resize(4, 2);
    print(given, "After resizing, (growing, given value)");
}
