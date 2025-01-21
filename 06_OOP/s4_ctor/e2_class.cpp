/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: ctor / dtor on class
 */
#include <iostream>

class Point
{
  private:
    int x_;
    const int y_;

  public:
    // the default ctor
    Point() : x_{0}, y_{0}
    {
    }

    // a plain explicit ctor
    explicit Point(int x) : x_{x}, y_{0}
    {
    }

    // another plain ctor
    Point(int x, int y) : x_{x}, y_{y}
    {
    }

    // the dtor
    ~Point()
    {
        std::cout << "dtor " << x_ << ' ' << y_ << '\n';
    }

    // a getter
    int x()
    {
        return x_;
    }

    // a setter
    void x(int x)
    {
        x_ = x;
    }

    // a getter
    int y()
    {
        return y_;
    }

    // a modifier
    void increaseX(int delta)
    {
        x_ += delta;
    }
};

int main()
{
    // default ctor
    Point a;
    std::cout << "a is " << a.x() << ' ' << a.y() << '\n';

    // more readable invocation of default ctor
    Point b{};
    std::cout << "b is " << b.x() << ' ' << b.y() << '\n';

    // plain ctors
    Point c{3, 4};
    std::cout << "c is " << c.x() << ' ' << c.y() << '\n';

    Point d{5, 6};
    d.increaseX(3);
    std::cout << "d is " << d.x() << ' ' << d.y() << '\n';

    // Point(int x) is explicit! Here can't be seen
    // Point e = 42;

    // explicit conversion from int to Point by ctor
    Point e{42};
    std::cout << "e is " << e.x() << ' ' << e.y() << '\n';

    // explicit conversion from int to Point by static cast
    Point f = static_cast<Point>(7);
    std::cout << "f is " << f.x() << ' ' << f.y() << '\n';
}
