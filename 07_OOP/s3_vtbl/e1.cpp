/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * virtual method
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

    virtual double distance_from_origin() const
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

    double distance_from_origin() const override
    {
        return sqrt(x() * x() + y() * y() + z_ * z_);
    }
};

int main()
{
    const Point a{8, 1};
    std::cout << "Distance from origin is " << a.distance_from_origin() << '\n';

    const Point3D b{8, 1, 5};
    std::cout << "Distance from origin is " << b.distance_from_origin() << '\n';

    Point *pp = new Point3D{8, 1, 5};
    std::cout << "Distance from origin is " << pp->distance_from_origin() << '\n';
    delete pp;
}
