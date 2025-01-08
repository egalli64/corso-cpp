/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector: basic methods
 */
#include <iostream>
#include <string>
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
    std::vector<int> empty;
    std::cout << "Size of an empty vector is " << empty.size() << '\n';

    std::vector<int> anotherEmpty{};
    std::cout << "Size of another empty vector is " << empty.size() << '\n';

    // notice: here can't be used the unversal initializer!
    std::vector<int> filled(5, -1);
    print(filled, "A vector filled with a given value");

    // no filling for vector
    // values.fill(-1);

    // notice the difference between the fill ctor and the initializer list ctor
    std::vector<int> given{6, 4};
    print(given, "A vector with two given values");

    std::vector<std::string> sv{"hello", "goodbye"};
    print(sv, "A string vector");

    // increase all the elements
    for (int &cur : given)
    {
        cur += 1;
    }
    print(given, "Increased values");
}
