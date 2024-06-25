/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * ctor / dtor on class
 */
#include <iostream>

namespace
{
/**
 * @brief A simple class
 */
class Point
{
  private:
    int x_;
    const int y_;

  public:
    /**
     * @brief the default ctor
     */
    Point() : x_{0}, y_{0}
    {
    }

    /**
     * @brief a plain explicit ctor
     */
    explicit Point(int x) : x_{x}, y_{0}
    {
    }

    /**
     * @brief another plain ctor
     */
    Point(int x, int y) : x_{x}, y_{y}
    {
    }

    /**
     * @brief dtor
     */
    ~Point()
    {
        std::cout << "dtor " << x_ << ' ' << y_ << '\n';
    }

    /**
     * @brief x getter
     */
    int x()
    {
        return x_;
    }

    /**
     * @brief y getter
     */
    int y()
    {
        return y_;
    }

    /**
     * @brief x mutator
     */
    void increase_x(int delta)
    {
        x_ += delta;
    }
};
} // namespace

int main()
{
    // implicit call to default ctor
    Point a;
    std::cout << "a is " << a.x() << ' ' << a.y() << '\n';

    // explicit call to default ctor
    Point b{};
    std::cout << "b is " << b.x() << ' ' << b.y() << '\n';

    // plain ctors
    Point c{3, 4};
    std::cout << "c is " << c.x() << ' ' << c.y() << '\n';

    Point d{5, 6};
    d.increase_x(3);
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
