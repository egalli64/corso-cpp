/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lambda - violation of noexcept
 */
#include <exception>
#include <iostream>

int main()
{
    try
    {
        // violating the noexcept contract!
        []() noexcept { throw std::runtime_error("Teminate!"); }();
    }
    catch (...)
    {
        std::cout << "You won't see this!\n";
    }
}
