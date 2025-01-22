/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lambda - deduced return type
 */
#include <iostream>
#include <limits>

int main()
{
    // bool is deduced
    auto b = [] { return true; }();
    std::cout << "The returned bool: " << b << ", size: " << sizeof(b) << '\n';

    // char is deduced
    auto c = [] { return 'x'; }();
    std::cout << "The returned char: " << c << ", size: " << sizeof(c) << '\n';

    // int is deduced
    auto vi = [] { return 42; }();
    std::cout << "The returned int: " << vi << ", size: " << sizeof(vi) << '\n';

    // long is deduced
    auto vl = [] { return 5'000'000'000; }();
    std::cout << "The returned long: " << vl << ", size: " << sizeof(vl) << '\n';

    auto vl2 = [] { return 42L; }();
    std::cout << "The returned long: " << vl2 << ", size: " << sizeof(vl2) << '\n';

    // float is deduced
    auto vf = [] { return 3.6F; }();
    std::cout << "The returned float: " << vf << ", size: " << sizeof(vf) << '\n';

    // double is deduced
    auto vd = [] { return std::numeric_limits<double>::max(); }();
    std::cout << "The returned double: " << vd << ", size: " << sizeof(vd) << '\n';

    // long double is deduced
    auto vld = [] { return 1e400L; }();
    std::cout << "The returned long double: " << vld << ", size: " << sizeof(vld) << '\n';

    // long double is deduced
    auto vld2 = [] { return std::numeric_limits<long double>::max(); }();
    std::cout << "The returned long double: " << vld2 << ", size: " << sizeof(vld2) << '\n';
}
