/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: operator overloading for an enum class
 */
#include <iostream>

enum class Day
{
    MON = 0,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN,
    SZ = 7
};

std::ostream &operator<<(std::ostream &os, const Day &day)
{
    switch (day)
    {
    case Day::MON:
        os << "Monday";
        break;
    case Day::TUE:
        os << "Tuesday";
        break;
    case Day::WED:
        os << "Wednesday";
        break;
    case Day::THU:
        os << "Thursday";
        break;
    case Day::FRI:
        os << "Friday";
        break;
    case Day::SAT:
        os << "Saturday";
        break;
    case Day::SUN:
        os << "Sunday";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

// prefix ++
Day &operator++(Day &day)
{
    day = static_cast<Day>((static_cast<int>(day) + 1) % (static_cast<int>(Day::SZ)));
    return day;
}

// postfix ++
Day operator++(Day &day, int)
{
    Day cur = day;
    day = static_cast<Day>((static_cast<int>(day) + 1) % (static_cast<int>(Day::SZ)));
    return cur;
}

// prefix --
Day &operator--(Day &day)
{
    day = (day == Day::MON) ? Day::SUN : static_cast<Day>((static_cast<int>(day) - 1));
    return day;
}

// postfix --
Day operator--(Day &day, int)
{
    Day cur = day;
    day = (day == Day::MON) ? Day::SUN : static_cast<Day>((static_cast<int>(day) - 1));
    return cur;
}

int main()
{
    Day cur{Day::MON};

    std::cout << "Current day is " << cur << '\n';
    std::cout << "Pre-decrement of current day: " << --cur << '\n';
    std::cout << "Pre-increment of current day: " << ++cur << '\n';
    std::cout << "Post-increment of current day: " << cur++ << '\n';
    std::cout << "Current day is " << cur << '\n';
    std::cout << "Post-decrement of current day: " << cur-- << '\n';
    std::cout << "Post-decrement of current day: " << cur-- << '\n';
    std::cout << "Current day is " << cur << '\n';
}
