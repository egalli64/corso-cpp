/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * operator overloading
 */
#include <iostream>

/**
 * @brief a function object
 */
class Adder
{
  private:
    const int addendum_;

  public:
    /**
     * @brief ctor
     */
    Adder(int addendum) : addendum_(addendum)
    {
    }

    /**
     * @brief overload for the () operator
     */
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
