/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * operator overloading
 */
#include <iostream>

/**
 * @brief collect the days
 */
enum class Day
{
    mon = 0,
    tue,
    wed,
    thu,
    fri,
    sat,
    sun,
    // having the size as "day" makes the code more compact, but maybe less readable
    size = 7
};

/**
 * @brief put to operator for days
 */
std::ostream &operator<<(std::ostream &os, const Day &day)
{
    switch (day)
    {
    case Day::mon:
        os << "Monday";
        break;
    case Day::tue:
        os << "Tuesday";
        break;
    case Day::wed:
        os << "Wednesday";
        break;
    case Day::thu:
        os << "Thursday";
        break;
    case Day::fri:
        os << "Friday";
        break;
    case Day::sat:
        os << "Saturday";
        break;
    case Day::sun:
        os << "Sunday";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

/**
 * @brief prefix ++ operator
 */
Day &operator++(Day &day)
{
    day = static_cast<Day>((static_cast<int>(day) + 1) % (static_cast<int>(Day::size)));
    return day;
}

/**
 * @brief postfix ++ operator
 */
Day operator++(Day &day, int)
{
    Day cur = day;
    day = static_cast<Day>((static_cast<int>(day) + 1) % (static_cast<int>(Day::size)));
    return cur;
}

/**
 * @brief prefix ++ operator
 */
Day &operator--(Day &day)
{
    day = (day == Day::mon) ? Day::sun : static_cast<Day>((static_cast<int>(day) - 1));
    return day;
}

/**
 * @brief postfix ++ operator
 */
Day operator--(Day &day, int)
{
    Day cur = day;
    day = (day == Day::mon) ? Day::sun : static_cast<Day>((static_cast<int>(day) - 1));
    return cur;
}

int main()
{
    Day cur = Day::mon;

    std::cout << "Current day is " << cur << '\n';
    std::cout << "Pre-decrement of current day: " << --cur << '\n';
    std::cout << "Pre-increment of current day: " << ++cur << '\n';
    std::cout << "Post-increment of current day: " << cur++ << '\n';
    std::cout << "Current day is " << cur << '\n';
    std::cout << "Post-decrement of current day: " << cur-- << '\n';
    std::cout << "Post-decrement of current day: " << cur-- << '\n';
    std::cout << "Current day is " << cur << '\n';
}
