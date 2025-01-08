/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL string: comparison
 */
#include <iostream>
#include <string>

int main()
{
    std::string s1 = "one";
    std::cout << "s1 is " << s1 << '\n';

    std::string s2 = "two";
    std::cout << "s2 is " << s2 << '\n';

    std::string t = s1;
    std::cout << "t is " << t << "\n\n";

    // ==
    if (s1 == t)
    {
        std::cout << "s1 is equal to t\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    // !=
    if (s1 != s2)
    {
        std::cout << "s1 is not equal to s2\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    // <
    if (s1 < s2)
    {
        std::cout << "s1 is less than s2\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    // <=
    if (s1 <= s2 && s1 <= t)
    {
        std::cout << "s1 is less or equal s2 and s1 is less or equal t\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }
    
    // >
    if (s2 > s1)
    {
        std::cout << "s2 is greater than s1\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    // >=
    if (s2 >= s1 && t >= s1)
    {
        std::cout << "s2 is greater or equal s1 and t is greater or equal s1\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }
}
