/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * throw own exception
 */
#include <exception>
#include <iostream>

namespace
{
class MyException : public std::exception
{
  public:
    const char *what() const noexcept override
    {
        return "Something bad happened";
    }
};

/**
 * @brief a function that throws an exception
 * @throw a MyException
 */
void risky()
{
    throw MyException();
}
} // namespace

int main()
{
    try
    {
        risky();
    }
    catch (const std::exception &me)
    {
        std::cout << me.what() << '\n';
    }

    std::cout << "Bye\n";
}
