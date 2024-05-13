/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * shallow vs deep copy
 */
#include <iostream>

class Point
{
  private:
    int x_;
    int y_;

  public:
    Point(int x, int y) : x_{x}, y_{y}
    {
    }
    ~Point()
    {
        std::cout << "dtor " << x_ << ", " << y_ << '\n';
    }

    // Point(const Point&) = delete; // no copy ctor
    // Point& operator=(const Point&) = delete; // no assigment operator

    int x()
    {
        return x_;
    }
    int y()
    {
        return y_;
    }
    void horizontalMove(int delta)
    {
        x_ += delta;
    }
};

int main()
{
    // no compiler generated default ctor
    // Point a;

    Point b{12, 23};
    std::cout << "b: " << b.x() << ", " << b.y() << '\n';

    // compiler generated copy ctor
    Point c = b;
    Point d{b};

    c.horizontalMove(12);
    d.horizontalMove(-7);

    std::cout << "c is a deep copy _by copy ctor_ of b (right shifted): " << c.x() << ", " << c.y() << '\n';
    std::cout << "d is a deep copy _by copy ctor_ of b (left shifted): " << d.x() << ", " << d.y() << '\n';
    std::cout << "b has not changed: " << b.x() << ", " << b.y() << '\n';

    // compiler generated assigment operator
    d = c;
    d.horizontalMove(-4);
    std::cout << "d is a deep copy _by assignment_ of c (left shifted): " << d.x() << ", " << d.y() << '\n';
    std::cout << "c has not changed: " << c.x() << ", " << c.y() << '\n';

    Point &e = b;
    e.horizontalMove(-2);
    std::cout << "e is a shallow copy _by reference_ of b (left shifted): " << e.x() << ", " << e.y() << '\n';
    std::cout << "b HAS changed: " << b.x() << ", " << b.y() << '\n';
}
