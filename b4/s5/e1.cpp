/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * overload
 */
#include <iostream>
using namespace std;

void swap(int &left, int &right)
{
    cout << "swapping integers\n";
    int temp = left;
    left = right;
    right = temp;
}

void swap(double &left, double &right)
{
    cout << "swapping doubles\n";
    double temp = left;
    left = right;
    right = temp;
}

int main()
{
    int a{42};
    int b{18};

    cout << "a is " << a << " b is " << b << '\n';
    swap(a, b);
    cout << "a is " << a << " b is " << b << '\n';

    double d{42.82};
    double e{18.09};

    cout << "d is " << d << " e is " << e << '\n';
    swap(d, e);
    cout << "d is " << d << " e is " << e << '\n';
}
