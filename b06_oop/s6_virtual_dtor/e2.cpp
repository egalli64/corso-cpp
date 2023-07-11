/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * virtual dtor (fix!)
 */
#include <iostream>

class Animal
{
  private:
    std::string name_;

  public:
    Animal(const std::string &name) : name_(name)
    {
    }
    // virtual, as it should be
    virtual ~Animal()
    {
        std::cout << "Animal dtor for " << name_ << '\n';
    }

    const std::string &name() const
    {
        return name_;
    }
    virtual std::string fullName() const = 0;
};

class Dog : public Animal
{
  private:
    std::string owner_;

  public:
    Dog(const std::string &name, const std::string &owner) : Animal(name), owner_(owner)
    {
    }
    ~Dog()
    {
        std::cout << "Dog dtor, owner " << owner_ << '\n';
    }

    std::string fullName() const override
    {
        return Animal::name() + " owned by " + owner_;
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

    Animal *dick = new Dog{"Dick", "Douglas Adams"};
    std::cout << dick->fullName() << '\n';
    // both dtor correctly called
    delete dick;
}
