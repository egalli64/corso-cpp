/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::string - equality/assignment operators
 */
#include <iostream>
#include <string>

int main()
{
    // constructing strings
    std::string hello{"Hello"};
    std::string s = "C++";
    std::string t = hello + ' ' + s;
    std::cout << t << '\n';

    // copy-assign
    std::cout << "Before copy: " << s << '\n';
    s = t;
    std::cout << "After copy: " << s << '\n';

    if (s == t)
    {
        std::cout << "As expected, s is equal to t\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    if (s != hello)
    {
        std::cout << "As expected, s is not equal to hello\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }
}
