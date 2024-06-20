/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * class - declared in header, its methods are defined here
 */
#include "Point.hpp"
#include <iostream>

Point::Point(int x, int y) : x_(x), y_(y)
{
}

int Point::x()
{
    return x_;
}

int Point::y()
{
    return y_;
}

void Point::increase_x(int delta)
{
    x_ += delta;
}

int main()
{
    Point a{34, 3};
    std::cout << "A point: " << a.x() << ' ' << a.y() << '\n';

    Point *p = &a;
    std::cout << "Same point, accessed by pointer: " << p->x() << ' ' << p->y() << '\n';

    Point &r = a;
    r.increase_x(5);
    std::cout << "Same point, modified by reference, accessed by original name: " << a.x() << ' ' << a.y() << '\n';
}
