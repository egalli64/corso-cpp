#include <exception>
#include <iostream>

class MyException : public std::exception
{
  public:
    const char *what() const noexcept override
    {
        return "Something bad happened";
    }
};

void risky()
{
    throw MyException();
}

int main()
{
    try
    {
        risky();
    }
    catch (std::exception &me)
    {
        std::cout << me.what() << '\n';
    }

    std::cout << "Bye\n";
}
