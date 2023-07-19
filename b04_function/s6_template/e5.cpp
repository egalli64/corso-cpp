#include <iostream>

template <typename T> T max(const T& a, const T& b)
{
    return a > b ? a : b;
}

int main()
{
    int a = max(5, 10);
    std::cout << "Max is: " << a << '\n';

    // int a2 = max(5, '1');
    // std::cout << "Max is: " << a << '\n';

    float b = max(3.14f, 2.71f);
    std::cout << "Max is: " << b << '\n';

    char c = max('a', 'z');
    std::cout << "Max is: " << c << '\n';
}
