/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: operator overloading, function object
 */
#include <iostream>

// A function object
class Adder
{
  private:
    const int addendum_;

  public:
    Adder(int addendum) : addendum_(addendum)
    {
    }

    int operator()(int value) const
    {
        return value + addendum_;
    }
};

int main()
{
    Adder add42{42};
    std::cout << add42(18) << '\n';
}
