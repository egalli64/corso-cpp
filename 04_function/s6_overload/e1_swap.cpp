/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * overload
 */
#include <iostream>

namespace
{
/**@brief swap integers */
void swap(int &left, int &right)
{
    std::cout << "swapping integers\n";
    int temp = left;
    left = right;
    right = temp;
}

/**@brief swap doubles */
void swap(double &left, double &right)
{
    std::cout << "swapping doubles\n";
    double temp = left;
    left = right;
    right = temp;
}

/**@brief swap strings */
void swap(std::string &left, std::string &right)
{
    std::cout << "swapping strings\n";
    std::string temp = left;
    left = right;
    right = temp;
}
} // namespace

int main()
{
    int a = 42;
    int b = 18;

    std::cout << "a is " << a << ", b is " << b << '\n';
    swap(a, b);
    std::cout << "a is " << a << ", b is " << b << '\n';
    std::cout << "---\n";

    double c = 42.82;
    double d = 18.09;

    std::cout << "c is " << c << ", d is " << d << '\n';
    swap(c, d);
    std::cout << "c is " << d << ", d is " << d << '\n';

    std::string s = "Hello";
    std::string t = "Ciao";
    std::cout << "s is '" << s << "', t is '" << t << "'\n";
    swap(s, t);
    std::cout << "s is '" << s << "', t is '" << t << "'\n";
}
