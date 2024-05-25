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
    ALPHA,
    BETA = 28
};

enum
{
    SOME_VALUE = 99
};

// improved enumeration - scoped and strongly typed
enum class GreekLetter
{
    ALPHA,
    BETA = 28
};

Greek f()
{
    return ALPHA;
}

GreekLetter g()
{
    return GreekLetter::ALPHA;
}
} // namespace

int main()
{
    std::cout << "ALPHA is " << ALPHA << " and BETA is " << BETA << '\n';
    std::cout << "ALPHA is " << static_cast<int>(GreekLetter::ALPHA);
    std::cout << " and BETA is " << static_cast<int>(GreekLetter::BETA) << '\n';

    Greek x = f();
    // warning - probably meaningless code
    // if (x == SOME_VALUE){ std::cout << "Unexpected\n"; }

    // no warning - probably meaningless code
    if (x == 42)
    {
        std::cout << "Unexpected\n";
    }

    GreekLetter y = g();
    // won't compile
    // if (y == SOME_VALUE) {std::cout << "Unexpected\n";}
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
        SAT,
        SUN
    };
    std::cout << "SAT is " << static_cast<bool>(WeekendDay::SAT);
    std::cout << " and SUN is " << static_cast<bool>(WeekendDay::SUN) << '\n';
}
