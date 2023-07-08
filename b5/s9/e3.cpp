/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * operator overloading
 */
#include <iostream>
using namespace std;

// A function object
class Adder
{
private:
    const int addendum_;

public:
    Adder(int addendum) : addendum_(addendum) {}

    int operator()(int value) const { return value + addendum_; }
};

int main()
{
    Adder add42{42};
    cout << add42(18) << '\n';
}
