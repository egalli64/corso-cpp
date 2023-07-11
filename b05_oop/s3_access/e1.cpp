/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * class
 */
#include <iostream>

/**
 * @brief A more structured class
 */
class Point
{
  private:
    int x_;
    int y_;

  public:
    Point(int x, int y) : x_(x), y_(y)
    {
    }

    int x()
    {
        return x_;
    }
    int y()
    {
        return y_;
    }
    void increaseX(int delta)
    {
        x_ += delta;
    }
};

int main()
{
    Point a{34, 3};
    std::cout << a.x() << ' ' << a.y() << '\n';

    Point *p{&a};
    std::cout << p->x() << ' ' << p->y() << '\n';

    Point &r{a};
    r.increaseX(5);
    std::cout << a.x() << ' ' << a.y() << '\n';
}
