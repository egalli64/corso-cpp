/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Protected inheritance
 */
#include "Tail.hpp"
#include <iostream>

/**
 * @brief Dog HAS-A Tail
 * @note the tail access is shared with derived classes
 */
class Dog : protected Tail
{
  protected:
    const std::string name_;

  public:
    /**
     * @brief ctor
     */
    Dog(const std::string &name, int count) : Tail{count}, name_{name}
    {
        std::cout << "Dog ctor, name is " << name_ << '\n';
    }

    /**
     * @brief dtor
     */
    ~Dog() override
    {
        std::cout << "Dog dtor, name is " << name_ << '\n';
    }

    /**
     * @brief a method that uses its composed tail object
     */
    void bark()
    {
        std::cout << name_ << ": bark! ";
        wag();
    }

    /**
     * @brief a virtual method
     */
    virtual void eat()
    {
        std::cout << name_ << ": eat\n";
    }
};

/**
 * @brief Poodle IS-A Dog
 * @note the tail access is granted to Poodle from Dog
 */
class Poodle : public Dog
{
  public:
    /**
     * @brief ctor
     */
    Poodle(const std::string &name) : Dog{name, 2}
    {
        std::cout << "Poodle ctor, name is " << name_ << '\n';
    }

    /**
     * @brief dtor
     */
    ~Poodle() override
    {
        std::cout << "Poodle dtor, name is " << name_ << '\n';
    }

    /**
     * @brief
     */
    void eat() override
    {
        std::cout << name_ << ": eat ";
        wag();
    }
};

int main()
{
    Dog tom{"Tom", 3};
    tom.bark();
    tom.eat();

    Poodle bob{"Bob"};
    bob.bark();
    bob.eat();
}
