/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by reference
 */
#include <iostream>

namespace
{
int hidden_value = 42;

const int &answer()
{
    return hidden_value;
}
} // namespace

int main()
{
    const int &a = answer();

    // won't compile
    // x += 1;
    std::cout << "The answer a is " << a << '\n';

    int b = answer();
    b += 1;
    std::cout << "The answer b is " << b << '\n';
    std::cout << "The hidden value is " << hidden_value << '\n';

    // won't compile
    // int& c = answer();
}
