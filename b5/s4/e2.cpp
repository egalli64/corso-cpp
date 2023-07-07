/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * ctor / dtor on class
 */
#include <iostream>
using namespace std;

class Point
{
private:
    int x_;
    const int y_;

public:
    // the default ctor
    Point() : x_{0}, y_{0} {}
    // a plain explicit ctor
    explicit Point(int x) : x_{x}, y_{0} {}
    // another plain ctor
    Point(int x, int y) : x_{x}, y_{y} {}

    // the dtor
    ~Point() { cout << "dtor " << x_ << ' ' << y_ << '\n'; }

    int x() { return x_; }
    int y() { return y_; }

    void increaseX(int delta) { x_ += delta; }
};

int main()
{
    // default ctor
    Point a;
    cout << "a is " << a.x() << ' ' << a.y() << '\n';

    Point b{};
    cout << "b is " << b.x() << ' ' << b.y() << '\n';

    // plain ctors
    Point c(3, 4);
    cout << "c is " << c.x() << ' ' << c.y() << '\n';

    Point d{5, 6};
    d.increaseX(3);
    cout << "d is " << d.x() << ' ' << d.y() << '\n';

    // can't see the explicit constructor
    // Point e = 42;

    // explicit conversion from int to Point by ctor
    Point e{42};
    cout << "e is " << e.x() << ' ' << e.y() << '\n';

    // explicit conversion from int to Point by static cast
    Point f = static_cast<Point>(7);
    cout << "f is " << f.x() << ' ' << f.y() << '\n';
}
