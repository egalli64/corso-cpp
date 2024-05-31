/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * throw - try / catch
 */
#include <iostream>

namespace
{
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
