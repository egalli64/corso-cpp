/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * placement new
 */
#include <iostream>
#include <new>

class Simple
{
  private:
    int id_;

  public:
    Simple(int id) : id_(id)
    {
        std::cout << "Ctor for " << id_ << '\n';
    }

    ~Simple()
    {
        std::cout << "Dtor for " << id_ << '\n';
    }

    int id()
    {
        return id_;
    }
};

int main()
{
    const size_t sz = sizeof(Simple);
    char buffer[sz];

    Simple *simple = new (buffer) Simple(42);
    std::cout << "Simple id is " << simple->id() << '\n';
    simple->~Simple();
}
