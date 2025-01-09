/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL string: access to elements
 */
#include <iostream>
#include <string>

int main()
{
    std::string s = "hello";
    std::cout << s << " begins with '" << s[0] << "' and ends with '" << s[s.size() - 1] << "'\n";

    std::cout << "Undefined behavior (out of bounds): " << s[42] << "\n\n";

    try
    {
        std::cout << s << " begins with '" << s.at(0) << "' and ends with '" << s.at(s.size() - 1) << "'\n";
        std::cout << s.at(42) << '\n';
    }
    catch (std::out_of_range &ex)
    {
        std::cout << "Out of range exception: " << ex.what() << '\n';
    }
}
