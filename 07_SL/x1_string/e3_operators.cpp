/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::string - operators
 */
#include <iostream>
#include <string>

using namespace std::literals::string_literals;

int main()
{
    std::string alpha{"alpha"};
    std::string beta{"beta"};

    // less than
    if (alpha < beta)
    {
        std::cout << "alpha is less than beta\n";
    }
    else
    {
        std::cout << "unexpected!\n";
    }

    // less or equal
    if (alpha <= "alpha")
    {
        std::cout << "alpha is less or equal to self\n";
    }
    else
    {
        std::cout << "unexpected!\n";
    }

    // greater than
    if (beta > alpha)
    {
        std::cout << "beta is greater than alpha\n";
    }
    else
    {
        std::cout << "unexpected!\n";
    }

    // greater or equal
    if (beta >= "beta"s)
    {
        std::cout << "beta is greater or equal to self\n";
    }
    else
    {
        std::cout << "unexpected!\n";
    }
}
