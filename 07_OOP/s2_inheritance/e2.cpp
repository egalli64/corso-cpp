/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * inheritance
 */
#include <cmath>
#include <iostream>

/**
 * @brief a simple base class
 */
class Couple
{
  private:
    int first_;
    int second_;

  public:
    /**
     * @brief ctor
     */
    Couple(int first, int second) : first_(first), second_(second)
    {
    }

    /**
     * @brief first getter
     */
    int first() const
    {
        return first_;
    }

    /**
     * @brief second getter
     */
    int second() const
    {
        return second_;
    }

    /**
     * @brief first setter
     */
    void first(const int first)
    {
        first_ = first;
    }

    /**
     * @brief second setter
     */
    void second(const int second)
    {
        second_ = second;
    }
};

/**
 * @brief put-to overload for Couple to ostream
 */
std::ostream &operator<<(std::ostream &os, const Couple &couple)
{
    return os << '(' << couple.first() << ", " << couple.second() << ')';
}

/**
 * @brief Point IS-A Couple
 */
class Point : public Couple
{
  public:
    /**
     * @brief ctor, explicitly call Couple ctor
     */
    Point(const int x, const int y) : Couple(x, y)
    {
    }

    /**
     * @brief a utility method
     */
    double distance_from_origin() const
    {
        return sqrt(first() * first() + second() * second());
    }
};

int main()
{
    Couple couple{4, 3};
    std::cout << "Couple: " << couple << '\n';

    Point point{8, 1};
    std::cout << "Point: " << point << " distance from origin is " << point.distance_from_origin() << '\n';
}
