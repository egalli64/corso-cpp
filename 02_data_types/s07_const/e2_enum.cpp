/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * enum vs enum class
 */
#include <iostream>

namespace
{
// simple enumeration
enum Greek
{
    alpha,
    beta = 28
};

enum
{
    some_value = 99
};

// improved enumeration - scoped and strongly typed
enum class GreekLetter
{
    alpha,
    beta = 28
};

Greek f()
{
    return alpha;
}

GreekLetter g()
{
    return GreekLetter::alpha;
}
} // namespace

int main()
{
    std::cout << "alpha is " << alpha << " and beta is " << beta << '\n';
    std::cout << "alpha is " << static_cast<int>(GreekLetter::alpha);
    std::cout << " and beta is " << static_cast<int>(GreekLetter::beta) << '\n';

    Greek x = f();
    // warning - probably meaningless code
    // if (x == some_value){ std::cout << "Unexpected\n"; }

    // no warning - probably meaningless code
    if (x == 42)
    {
        std::cout << "Unexpected\n";
    }

    GreekLetter y = g();
    // won't compile
    // if (y == some_value) {std::cout << "Unexpected\n";}
    // if (y == 42) {std::cout << "Unexpected\n";}

    // if really needed, an explicit cast is required
    int yi = static_cast<int>(y);

    if (yi == 42)
    {
        std::cout << "Unexpected\n";
    }

    // using an integral type different from int
    enum class WeekendDay : bool
    {
        sat,
        sun
    };
    std::cout << "sat is " << static_cast<bool>(WeekendDay::sat);
    std::cout << " and sun is " << static_cast<bool>(WeekendDay::sun) << '\n';
}
