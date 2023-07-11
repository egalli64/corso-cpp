/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * lambda: return type deduction
 */
#include <iostream>

int main()
{
    // return type is deduced as double
    auto square = [](double value)
    {
        return value * value;
    };

    double original = 42.24;
    std::cout << original << " squared is " << square(original) << '\n';
}
