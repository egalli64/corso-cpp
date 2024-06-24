/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * template
 */
#include <iostream>
#include <string>
#include <utility>

namespace my
{
/**
 * @brief my template swap function
 *
 * @param left to be swapped
 * @param right to be swapped
 */
template <typename T> void swap(T &left, T &right)
{
    T temp = std::move(left);
    left = std::move(right);
    right = std::move(temp);
}
} // namespace my

int main()
{
    int a = 42;
    int b = 18;

    std::cout << "My swap on int\n";
    std::cout << "a is " << a << " b is " << b << '\n';
    my::swap(a, b);
    std::cout << "a is " << a << " b is " << b << "\n\n";

    std::cout << "Standard swap on int\n";
    std::swap(a, b);
    std::cout << "a is " << a << " b is " << b << "\n\n";

    std::string s = "hello";
    std::string t = "ciao";

    std::cout << "My swap on string\n";
    std::cout << "s is " << s << " t is " << t << '\n';
    my::swap(s, t);
    std::cout << "s is " << s << " t is " << t << '\n';
}
