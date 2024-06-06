/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * dynamic_cast vs reinterpret_cast
 */
#include <iostream>

class Base
{
  public:
    virtual ~Base()
    {
    }
};

class Extended : public Base
{
    int x;

  public:
    Extended() : x(33)
    {
    }
    void f()
    {
        std::cout << "In f() " << x << "\n";
    }
};

struct Other
{
    virtual ~Other()
    {
    }
};

int main()
{
    Base *base = new Extended();

    Extended *ext = dynamic_cast<Extended *>(base);
    if (ext != nullptr)
    {
        ext->f();
    }

    Other other;
    ext = reinterpret_cast<Extended *>(&other);
    if (ext != nullptr)
    {
        ext->f();
        std::cout << "This is an Extended?\n";
    }
}