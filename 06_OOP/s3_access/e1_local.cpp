/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * class
 */
#include <iostream>

namespace
{
/**
 * @brief A more structured class
 */
class Point
{
  private:
    int x_;
    int y_;

  public:
    /**
     * @brief initialize all fields
     */
    Point(int x, int y) : x_(x), y_(y)
    {
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
    Point a{34, 3};
    std::cout << "A point: " << a.x() << ' ' << a.y() << '\n';

    Point *p = &a;
    std::cout << "Same point, accessed by pointer: " << p->x() << ' ' << p->y() << '\n';

    Point &r = a;
    r.increase_x(5);
    std::cout << "Same point: accessed by reference: " << a.x() << ' ' << a.y() << '\n';
}
