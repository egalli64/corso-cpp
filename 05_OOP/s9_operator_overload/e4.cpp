/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * operator overloading + friend
 */
#include <iostream>
#include <string>

class Point
{
    friend std::ostream &operator<<(std::ostream &os, const Point &point);

  private:
    int x_;
    int y_;
    const std::string label_;

  public:
    Point(int x, int y, const std::string &label) : x_(x), y_(y), label_(label)
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

    void horMove(int delta)
    {
        x_ += delta;
    }
    void vertMove(int delta)
    {
        y_ += delta;
    }

    std::ostream &write(std::ostream &os) const
    {
        return os << label_ << ": " << x_ << ", " << y_;
    }

    operator std::string() const
    {
        return label_ + ": " + std::to_string(x_) + ", " + std::to_string(y_);
    }
};

std::ostream &operator<<(std::ostream &os, const Point &point)
{
    return os << point.label_ << ": " << point.x_ << ", " << point.y_;

    // alternative approaches, no friendship required
    // return point.write(os);
    // return os << static_cast<std::string>(point);
}

int main()
{
    Point a{12, 5, "A"};

    std::cout << "Operator <<() leads to ";
    std::cout << a << '\n';

    std::cout << "Operator string() leads to ";
    std::cout << static_cast<std::string>(a) << '\n';

    std::cout << "Method write() leads to ";
    a.write(std::cout) << '\n';
}
