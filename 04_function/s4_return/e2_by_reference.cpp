/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by reference
 */
#include <iostream>

namespace
{
int hidden_value = 42;

/**
 * @brief make available an hidden value in read-only mode
 *
 * @return the hidden value
 */
const int &answer()
{
    return hidden_value;
}

/**
 * @brief Returning a reference to a local variable is wrong!
 *
 * @return a reference to a local variable
 */
const int &mistake()
{
    int bad = 42;

    std::cout << "This is a local variable: " << bad << '\n';

    return bad;
}
} // namespace

int main()
{
    const int &a = answer();

    // won't compile, a is a const ref
    // a += 1;
    std::cout << "The answer a is " << a << '\n';

    const int &b = mistake();
    // std::cout << "Undefined behavior: " << b << '\n';

    // assign a const ref to a modifiable variable by copy
    int c = answer();
    c += 1;
    std::cout << "The answer c is " << c << '\n';
    std::cout << "The hidden value is " << hidden_value << '\n';

    // won't compile, const is missing
    // int& d = answer();
}
