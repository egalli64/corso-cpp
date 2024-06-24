/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * catch all
 */
#include <iostream>

namespace
{
/**
 * @brief a function that throws an exception
 * @throw a c-string
 * @note throwing something that is not a std::exception is not considered a good idea
 */
void risky_1()
{
    throw "Not yet implemented";
}

/**
 * @brief a function that throws an exception
 * @throw an int
 * @note throwing something that is not a std::exception is not considered a good idea
 */
void risky_2()
{
    throw 1;
}

/**
 * @brief a function that throws an exception
 * @throw a double
 * @note throwing something that is not a std::exception is not considered a good idea
 */
void risky_3()
{
    throw 42.24;
}
} // namespace

int main()
{
    try
    {
        risky_1();
        risky_2();
        risky_3();
    }
    catch (int ex)
    {
        std::cout << "An int exception: " << ex << '\n';
    }
    catch (double ex)
    {
        std::cout << "A double exception: " << ex << '\n';
    }
    catch (...)
    {
        std::cout << "Something went wrong\n";
    }

    std::cout << "Bye\n";
}
