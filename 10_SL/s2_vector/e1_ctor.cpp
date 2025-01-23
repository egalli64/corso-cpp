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
    // an empty vector, implicit call to the default ctor
    std::vector<int> empty;
    std::cout << "Size of an empty vector is " << empty.size() << '\n';

    // another empty vector, explicit call to the default ctor
    std::vector<int> anotherEmpty{};
    std::cout << "Size of another empty vector is " << anotherEmpty.size() << '\n';

    // a vector sized 5, all the element initialized to -1
    // notice: here can't be used the unversal initializer!
    std::vector<int> filled(5, -1);
    print(filled, "A vector filled with a given value");

    // a vector sized 2, with 6 and 4 in it
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
