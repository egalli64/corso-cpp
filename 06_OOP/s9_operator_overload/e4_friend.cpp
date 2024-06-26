/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * operator overloading + friend
 */
#include <iostream>
#include <string>

/**
 * @brief a class with a friend
 */
class Point
{
    // declaring that this overload of operator << is a friend
    friend std::ostream &operator<<(std::ostream &, const Point &);

  private:
    int x_;
    int y_;
    const std::string label_;

  public:
    /**
     * @brief ctor
     */
    Point(int x, int y, const std::string &label) : x_(x), y_(y), label_(label)
    {
    }

    /**
     * @brief x getter
     */
    int x() const
    {
        return x_;
    }

    /**
     * @brief y getter
     */
    int y() const
    {
        return y_;
    }

    /**
     * @brief x modifier
     */
    void horMove(int delta)
    {
        x_ += delta;
    }

    /**
     * @brief y modifier
     */
    void vertMove(int delta)
    {
        y_ += delta;
    }

    /**
     * @brief helper to avoid the need of friend
     */
    std::ostream &write(std::ostream &os) const
    {
        return os << label_ << ": " << x_ << ", " << y_;
    }

    /**
     * @brief "type string" operator overload
     */
    operator std::string() const
    {
        return label_ + ": " + std::to_string(x_) + ", " + std::to_string(y_);
    }

    /**
     * @brief "type int" operator overload
     */
    operator int()
    {
        return x_ * y_;
    }
};

/**
 * @brief the operator put-to overload for point
 */
std::ostream &operator<<(std::ostream &os, const Point &point)
{
    // if << is not a friend, only public members are accessible
    // return os << point.x() << ", " << point.y();

    // when friend, it could access any member
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
