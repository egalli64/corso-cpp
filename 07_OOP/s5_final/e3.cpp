/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * pure virtual / final method
 */
#include <iostream>

// An abstract class
class Animal
{
  private:
    std::string name_;

  public:
    Animal(const std::string &name) : name_(name)
    {
    }

    const std::string &name() const
    {
        return name_;
    }
    // pure virtual method
    virtual std::string fullName() = 0;
};

class Dog : public Animal
{
  private:
    std::string owner_;

  public:
    Dog(const std::string &name, const std::string &owner) : Animal(name), owner_(owner)
    {
    }

    std::string fullName() override final
    {
        return Animal::name() + " owned by " + owner_;
    }
};

class Poodle : public Dog
{
  public:
    Poodle(const std::string &name, const std::string &owner) : Dog(name, owner)
    {
    }

    // can't override a final method
    // std::string fullName() override { return "Poodle " + Dog::fullName(); }
};

int main()
{
    Dog bob{"Bob", "Robert Smith"};
    std::cout << bob.fullName() << '\n';

    Poodle tom{"Tom", "Thomas Benson"};
    std::cout << tom.fullName() << '\n';
}
