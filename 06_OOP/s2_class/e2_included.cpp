/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * struct - defined in a header file
 */
#include "Point.hpp"
#include <iostream>

int main()
{
    Point a{5, 7};
    std::cout << a.x << ' ' << a.y << '\n';

    Point *p = &a;
    std::cout << p->x << ' ' << p->y << '\n';

    Point &r = a;
    r.x += 5;
    std::cout << r.x << ' ' << r.y << '\n';

    // !!! being on the stack, it is not initialized !!!
    Point b;
    std::cout << "Warning, not initialized: " << b.x << ' ' << b.y << '\n';

    Point *c = new Point;
    std::cout << c->x << ' ' << c->y << '\n';
}
