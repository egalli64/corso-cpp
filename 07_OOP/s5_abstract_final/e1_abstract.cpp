/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * abstract - virtual - concrete
 */
#include <iostream>

/**
 * @brief an abstract class
 */
class Animal
{
  private:
    std::string name_;

  public:
    /**
     * @brief ctor
     */
    Animal(const std::string &name) : name_(name)
    {
    }

    /**
     * @brief name getter
     */
    const std::string &name() const
    {
        return name_;
    }

    /**
     * @brief a pure virtual method
     */
    virtual std::string full_name() const = 0;

    /**
     * @brief dtor
     */
    virtual ~Animal()
    {
    }
};

/**
 * @brief derives from an abstract class, to be concrete must override the inherited abstract methods
 */
class Dog : public Animal
{
  private:
    std::string owner_;

  public:
    /**
     * @brief ctor
     */
    Dog(const std::string &name, const std::string &owner) : Animal(name), owner_(owner)
    {
    }

    /**
     * @brief (re)define the pure abstract method from the base class
     */
    std::string full_name() const override
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
    std::cout << bob.full_name() << '\n';

    std::cout << "It is a polimorphic dog\n";
    Animal *pa = &bob;
    std::cout << pa->full_name() << '\n';
}
