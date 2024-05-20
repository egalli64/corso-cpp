/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * casts
 */
#include <iostream>
#include <string>

int main()
{
    int x{static_cast<int>(42.7)};
    // automatic type deduction (here: double)
    auto y = 42.7;

    std::cout << "x is " << x << '\n';
    std::cout << "y is " << y << " is sized " << sizeof(y) << '\n';

    std::string s = "42";
    int i = std::stoi(s);
    std::cout << "From string to int (pre-incremented): " << ++i << '\n';

    s += ".27";
    double d{std::stod(s)};
    std::cout << "From string to double: " << d << '\n';

    std::cout << "From numeric to string, and concat: " << std::to_string(51) + std::to_string(8.931255) << '\n';
}
