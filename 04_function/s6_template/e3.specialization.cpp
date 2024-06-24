/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * template specialization
 */
#include <iostream>
#include <string>

namespace
{
/**
 * @brief a template function to sum up all the elements in the passed array
 *
 * @param values an array of T
 * @param size the array size
 * @return the sum
 */
template <typename T> T sum(T values[], int size)
{
    // rely on the T default ctor for initialization
    T result{};

    for (int i = 0; i < size; ++i)
    {
        result += values[i];
    }

    return result;
}

/**
 * @brief template specialization for std::string
 */
template <> std::string sum(std::string values[], int size)
{
    std::string result{};

    for (int i = 0; i < size - 1; ++i)
    {
        result += values[i];
        result.append(", ");
    }
    result += values[size - 1];

    return result;
}
} // namespace

int main()
{
    int a[]{42, 12, 27};
    std::cout << "Int sum is " << sum(a, 3) << '\n';

    double d[]{42.23, 12.84, 27.22};
    std::cout << "Double sum is " << sum(d, 3) << '\n';

    std::string s[]{"hello", "ciao", "hola"};
    std::cout << "String sum is " << sum(s, 3) << '\n';
}
