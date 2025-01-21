/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP - class
 */
#include <iostream>

/**
 * @brief A simple class (by class)
 */
class Point
{
  public:
    int x;
    int y;
};

int main()
{
    // aggregate initialization
    Point a{5, 7};
    std::cout << a.x << ' ' << a.y << '\n';

    // accessing the Point object by pointer
    Point *p = &a;
    p->x += 5;
    std::cout << p->x << ' ' << p->y << '\n';

    // accessing the Point object by reference
    Point &r = a;
    r.x += 5;
    std::cout << r.x << ' ' << r.y << '\n';

    // !!! a non-initialized object !!!
    Point b;
    std::cout << b.x << ' ' << b.y << '\n';
}
