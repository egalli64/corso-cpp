/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * ctor / dtor on struct
 */
#include <iostream>

struct Point
{
    int x;
    int y;

    // implicit - field are not initialized
    // Point() {}

    // disallow implicit constructor
    // Point() = delete;

    // explicit remark on generation of default ctor
    // Point() = default;

    // when a ctor is present, default constructor generation is implicitly disallowed
    // Point(int test) { x = y = test; }

    // explicit initialization of fields /1
    // Point() : x(0), y(0) { }

    // explicit initialization of fields /2
    // Point() { x = y = 0; }

    ~Point()
    {
        std::cout << "Point (" << x << ", " << y << ") removed\n";
    }
};

int main()
{
    // point is created on stack, implicit call to default ctor
    Point a;
    std::cout << "See default ctor to see if the point is correctly initialized: " << a.x << ' ' << a.y << '\n';
}
