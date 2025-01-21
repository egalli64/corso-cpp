/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: virtual method
 */
#include <cmath>
#include <iostream>

class Point
{
  private:
    const int x_;
    const int y_;

  public:
    Point(const int x, const int y) : x_(x), y_(y)
    {
    }

    int x() const
    {
        return x_;
    }

    int y() const
    {
        return y_;
    }

    virtual double distanceFromOrigin() const
    {
        return sqrt(x_ * x_ + y_ * y_);
    }
};

class Point3D : public Point
{
  private:
    const int z_;

  public:
    Point3D(const int x, const int y, const int z) : Point(x, y), z_(z)
    {
    }

    double distanceFromOrigin() const override
    {
        return sqrt(x() * x() + y() * y() + z_ * z_);
    }
};

int main()
{
    Point a{8, 1};
    std::cout << "Distance from origin is " << a.distanceFromOrigin() << '\n';

    Point3D b{8, 1, 5};
    std::cout << "Distance from origin is " << b.distanceFromOrigin() << '\n';

    // a Point ptr referring to a Point3D, polimorphism in action
    Point *c = new Point3D{1, 2, 3};
    std::cout << c->distanceFromOrigin();
}
