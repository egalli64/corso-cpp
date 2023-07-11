/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * inheritance
 */
#include <cmath>
#include <iostream>

class Couple
{
private:
    int first_;
    int second_;

public:
    Couple(const int first, const int second) : first_(first), second_(second) {}

    int first() const { return first_; }
    int second() const { return second_; }
    void first(const int first) { first_ = first; }
    void second(const int second) { second_ = second; }
};

std::ostream &operator<<(std::ostream &os, const Couple &couple)
{
    return os << '(' << couple.first() << ", " << couple.second() << ')';
}

class Point : public Couple
{
public:
    Point(const int x, const int y) : Couple(x, y) {}

    double distanceFromOrigin() const
    {
        return sqrt(first() * first() + second() * second());
    }
};

int main()
{
    Couple couple{4, 3};
    std::cout << "Couple: " << couple << '\n';

    Point point{8, 1};
    std::cout << "Point: " << point << " distance from origin is " << point.distanceFromOrigin() << '\n';
}
