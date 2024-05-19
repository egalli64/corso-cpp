/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * constants
 */
#include <iostream>

int main()
{
    std::cout << "\nConstants\n\n";
    // evaluated at compile time
    constexpr auto x{18};

    // error!
    // x += 1;

    // won't change
    const auto y{42};
    //	y += 1; // error!

    std::cout << "x is " << x << '\n';
    std::cout << "y is " << y << '\n';

    // simple enumeration
    enum
    {
        ALPHA,
        BETA = 28
    };

    std::cout << "ALPHA is " << ALPHA << " and BETA is " << BETA << '\n';

    // improved enumeration - scoped and strongly typed
    enum class GreekLetter
    {
        ALPHA = 42,
        BETA
    };
    std::cout << "ALPHA is " << static_cast<int>(GreekLetter::ALPHA);
    std::cout << " and BETA is " << static_cast<int>(GreekLetter::BETA) << '\n';

    enum class WeekendDay : bool
    {
        SAT,
        SUN
    };
    std::cout << "SAT is " << static_cast<int>(WeekendDay::SAT);
    std::cout << " and SUN is " << static_cast<int>(WeekendDay::SUN) << '\n';
}
