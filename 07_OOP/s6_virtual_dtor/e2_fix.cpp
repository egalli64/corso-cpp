/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * virtual dtor (fix!)
 */
#include <iostream>

/**
 * @brief A good virtual abstract class, the dtor is virtual
 */
class Animal
{
  private:
    const std::string name_;

  public:
    /**
     * @brief ctor
     */
    Animal(const std::string &name) : name_{name}
    {
    }

    /**
     * @brief dtor - virtual, as it should be
     */
    virtual ~Animal()
    {
        std::cout << "Animal dtor for " << name_ << '\n';
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
};

/**
 * @brief Dog IS-A concrete Animal
 */
class Dog : public Animal
{
  private:
    const std::string owner_;

  public:
    /**
     * @brief ctor
     */
    Dog(const std::string &name, const std::string &owner) : Animal{name}, owner_{owner}
    {
    }

    /**
     * @brief dtor
     */
    ~Dog() override
    {
        std::cout << "Dog dtor, owner " << owner_ << '\n';
    }

    /**
     * @brief override of a virtual method
     */
    std::string full_name() const override
    {
        return Animal::name() + " owned by " + owner_;
    }
};

/**
 * @brief create an Animal on the stack
 */
void bob_function()
{
    Dog bob{"Bob", "Robert Smith"};
    std::cout << bob.full_name() << '\n';
}

int main()
{
    bob_function();
    std::cout << "*** Bob correctly removed from stack\n";

    Dog *chip = new Dog{"Chip", "Charlie Parker"};
    std::cout << chip->full_name() << '\n';
    delete chip;
    std::cout << "*** Chip correctly deleted from heap\n";

    Animal *dick = new Dog{"Dick", "Douglas Adams"};
    std::cout << dick->full_name() << '\n';
    // both dtor correctly called
    delete dick;
    std::cout << "*** Dick correctly deleted from heap\n";
}
