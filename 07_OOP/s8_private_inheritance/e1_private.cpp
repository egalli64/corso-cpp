/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Private inheritance
 */
#include "Tail.hpp"
#include <iostream>

/**
 * @brief Dog HAS-A Tail
 */
class Dog : private Tail
{
  private:
    const std::string name_;

  public:
    /**
     * @brief ctor
     */
    Dog(const std::string &name, int count) : Tail(count), name_(name)
    {
    }

    /**
     * @brief a method that uses its composed tail object
     */
    void bark()
    {
        std::cout << name_ << ": bark! ";
        wag();
    }
};

int main()
{
    Dog tom{"Tom", 3};
    tom.bark();
    // Tail methods are not part of the dog interface
    // tom.wag();
}
