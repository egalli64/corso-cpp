/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * sort of casts between numeric types and string
 */
#include <iostream>
#include <string>

int main()
{
    std::string s = "42";
    int i = std::stoi(s);
    std::cout << "From string to int (pre-incremented): " << ++i << '\n';

    s += ".27";
    double d = std::stod(s);
    std::cout << "From string to double (halved): " << d / 2 << '\n';

    std::cout << "From numeric to string, and concat: " << std::to_string(51) + std::to_string(8.931255) << '\n';
}
