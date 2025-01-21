/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: abstract - virtual - concrete
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

    /**
     * @brief a pure virtual method
     */
    virtual std::string fullName() const = 0;
};

/**
 * derives from an abstract class, to be concrete must override the inherited abstract methods
 */
class Dog : public Animal
{
  private:
    std::string owner_;

  public:
    Dog(const std::string &name, const std::string &owner) : Animal(name), owner_(owner)
    {
    }

    /**
     * @brief override a pure virtual method
     */
    std::string fullName() const override
    {
        return Animal::name() + " owned by " + owner_;
    }
};

int main()
{
    // Can't instantiate an abstract class
    // Animal animal{"Tom"};

    Dog bob{"Bob", "Robert Smith"};
    std::cout << bob.name() << '\n';
    std::cout << bob.fullName() << '\n';

    std::cout << "It is a polimorphic dog\n";
    Animal *pa = &bob;
    std::cout << pa->fullName() << '\n';
}
