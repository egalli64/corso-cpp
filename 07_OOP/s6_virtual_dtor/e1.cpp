/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * virtual dtor (missing!)
 */
#include <iostream>

// Bad virtual class, the dtor is not virtual!
class BadVirtualAnimal
{
  private:
    std::string name_;

  public:
    BadVirtualAnimal(const std::string &name) : name_(name)
    {
        std::cout << "BadVirtualAnimal ctor " << name << '\n';
    }

    // it should be virtual!
    ~BadVirtualAnimal()
    {
        std::cout << "BadVirtualAnimal dtor for " << name_ << '\n';
    }

    const std::string &name() const
    {
        return name_;
    }
    virtual std::string fullName() const = 0;
};

class Dog : public BadVirtualAnimal
{
  private:
    std::string owner_;

  public:
    Dog(const std::string &name, const std::string &owner) : BadVirtualAnimal(name), owner_(owner)
    {
        std::cout << "Dog ctor " << owner << '\n';
    }

    ~Dog()
    {
        std::cout << "Dog dtor, owner " << owner_ << '\n';
    }

    std::string fullName() const override
    {
        return BadVirtualAnimal::name() + " owned by " + owner_;
    }
};

void bobFunction()
{
    Dog bob{"Bob", "Robert Smith"};
    std::cout << bob.fullName() << '\n';
}

int main()
{
    bobFunction();

    Dog *chip = new Dog{"Chip", "Charlie Parker"};
    std::cout << chip->fullName() << '\n';
    delete chip;

    BadVirtualAnimal *dick = new Dog{"Dick", "Douglas Adams"};
    std::cout << dick->fullName() << '\n';
    // The Dog dtor invocation usually is missing!
    delete dick;
}
