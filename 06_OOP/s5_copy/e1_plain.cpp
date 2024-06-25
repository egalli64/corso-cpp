/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * shallow vs deep copy
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
    int y_;

  public:
    /**
     * @brief ctor - initialize all data members
     */
    Point(int x, int y) : x_{x}, y_{y}
    {
    }

    /**
     * @brief dtor
     */
    ~Point()
    {
        std::cout << "dtor " << x_ << ", " << y_ << '\n';
    }

    // Point(const Point&) = delete; // no copy ctor
    // Point& operator=(const Point&) = delete; // no assigment operator

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
    void horizontal_move(int delta)
    {
        x_ += delta;
    }
};
} // namespace

int main()
{
    // no compiler generated default ctor
    // Point a;

    Point b{12, 23};
    std::cout << "b: " << b.x() << ", " << b.y() << '\n';

    // compiler generated copy ctor
    Point c = b;
    Point d{b};

    c.horizontal_move(12);
    std::cout << "c is a deep copy _by copy ctor_ of b (right shifted): " << c.x() << ", " << c.y() << '\n';

    d.horizontal_move(-7);
    std::cout << "d is a deep copy _by copy ctor_ of b (left shifted): " << d.x() << ", " << d.y() << '\n';

    std::cout << "b has not changed: " << b.x() << ", " << b.y() << '\n';

    // compiler generated assigment operator
    d = c;
    d.horizontal_move(-4);
    std::cout << "d is a deep copy _by assignment_ of c (left shifted): " << d.x() << ", " << d.y() << '\n';
    std::cout << "c has not changed: " << c.x() << ", " << c.y() << '\n';

    Point &e{b};
    e.horizontal_move(-2);
    std::cout << "e is a shallow copy _by reference_ of b (left shifted): " << e.x() << ", " << e.y() << '\n';
    std::cout << "b HAS changed: " << b.x() << ", " << b.y() << '\n';
}
