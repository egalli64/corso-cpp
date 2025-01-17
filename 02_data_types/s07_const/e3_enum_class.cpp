/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * enum class
 */
#include <iostream>

// modern enumeration - scoped and strongly typed
enum class GreekLetter
{
    ALPHA,
    BETA = 28
};

enum class LatinLetter
{
    A,
    B = 42
};

GreekLetter g()
{
    return GreekLetter::ALPHA;
}

int main()
{
    std::cout << "ALPHA is " << static_cast<int>(GreekLetter::ALPHA);
    std::cout << " and BETA is " << static_cast<int>(GreekLetter::BETA) << '\n';

    GreekLetter y = g();
    // won't compile: no operator "==" matches these operands
    // if (y == LatinLetter::B) { std::cout << "Unexpected\n"; }
    // if (y == 42) {std::cout << "Unexpected\n";}

    // if really needed, an explicit cast is required
    int yi = static_cast<int>(y);
    if (yi == 0)
    {
        std::cout << "Strange comparison, but at least the context is more clear\n";
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
