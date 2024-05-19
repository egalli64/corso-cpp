/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * struct
 */
#include <iostream>

/**
 * @brief A simple class
 */
struct Point
{
    int x;
    int y;
};

int main()
{
    Point a{5, 7};
    std::cout << a.x << ' ' << a.y << '\n';

    Point *p = &a;
    std::cout << p->x << ' ' << p->y << '\n';

    Point &r = a;
    r.x += 5;
    std::cout << r.x << ' ' << r.y << '\n';

    // !!! not initialized !!!
    Point b;
    std::cout << b.x << ' ' << b.y << '\n';
}
