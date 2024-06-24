/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * throw - try / catch
 */
#include <iostream>

namespace
{
/**
 * @brief a function that could throw an exception
 *
 * @param value it should not be 1
 * @throw 42 when value is 1
 * @note throwing something that is not a std::exception is not considered a good idea
 */
void risky(int value)
{
    if (value == 1)
    {
        throw 42;
    }
    std::cout << "Hello\n";
}
} // namespace

int main(int argc, char **argv)
{
    try
    {
        risky(argc);
    }
    catch (int exc)
    {
        std::cout << "Error detected: " << exc << '\n';
        std::cout << "You should pass at least an argument to this program!" << '\n';
    }

    std::cout << "Rest of code" << '\n';
}
