/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * template
 */
#include <iostream>
#include <string>
using namespace std;

namespace my
{
    template <typename T>
    void swap(T &left, T &right)
    {
        T temp = left;
        left = right;
        right = temp;
    }
}

int main()
{
    int a{42};
    int b{18};

    cout << "a is " << a << " b is " << b << '\n';
    my::swap(a, b);
    cout << "a is " << a << " b is " << b << '\n';

    string s{"hello"};
    string t{"ciao"};

    cout << "s is " << s << " t is " << t << '\n';
    my::swap(s, t);
    cout << "s is " << s << " t is " << t << '\n';
}
