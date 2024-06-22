/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * array
 */
#include <iostream>

namespace
{
constexpr size_t v_size = 10;
int values[v_size];
} // namespace

int main()
{
    std::cout << "size of an int[" << v_size << "] " << sizeof(values) << '\n';
    std::cout << "size of char[" << v_size << "] " << sizeof(char[v_size]) << '\n';
    std::cout << "size of double[" << v_size << "] " << sizeof(double[v_size]) << '\n';
    std::cout << '\n';

    std::cout << "Non-local arrays are default-initialized: ";
    for (size_t i = 0; i < v_size; ++i)
    {
        std::cout << values[i] << ' ';
    }
    std::cout << '\n';

    // g++ -Wall warning for possible uninitialized use
    int local_values[v_size];
    std::cout << "No assumption on local arrays: ";
    for (size_t i = 0; i < v_size; ++i)
    {
        std::cout << local_values[i] << ' ';
    }
    std::cout << '\n';
}
