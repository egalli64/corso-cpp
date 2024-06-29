/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * virtual dtor (missing!)
 */
#include <iostream>

/**
 * @brief !!! Bad virtual abstract class, the dtor is not virtual !!!
 */
class BadVirtualAnimal
{
  private:
    const std::string name_;

  public:
    /**
     * @brief ctor
     */
    BadVirtualAnimal(const std::string &name) : name_{name}
    {
        std::cout << "BadVirtualAnimal ctor " << name << '\n';
    }

    /**
     * @brief !!! it should be virtual !!!
     */
    ~BadVirtualAnimal()
    {
        std::cout << "BadVirtualAnimal dtor for " << name_ << '\n';
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
 * @brief Dog IS-A BadVirtualAnimal, concrete with a problem in the ctor
 */
class Dog : public BadVirtualAnimal
{
  private:
    const std::string owner_;

  public:
    /**
     * @brief ctor
     */
    Dog(const std::string &name, const std::string &owner) : BadVirtualAnimal{name}, owner_{owner}
    {
        std::cout << "Dog ctor " << owner << '\n';
    }

    /**
     * @brief !!! dtor - it is not virtual !!!
     */
    ~Dog()
    {
        std::cout << "Dog dtor, owner " << owner_ << '\n';
    }

    /**
     * @brief override of a virtual method
     */
    std::string full_name() const override
    {
        return BadVirtualAnimal::name() + " owned by " + owner_;
    }
};

/**
 * @brief create a BadVirtualAnimal on the stack
 */
void bob_function()
{
    Dog bob{"Bob", "Robert Smith"};
    std::cout << bob.full_name() << '\n';

    // when the object is allocated on the stack, it works fine
}

int main()
{
    bob_function();
    std::cout << "*** Bob correctly removed from stack\n";

    Dog *chip = new Dog{"Chip", "Charlie Parker"};
    std::cout << chip->full_name() << '\n';
    // warning, undefined behavior! But it works fine
    delete chip;
    std::cout << "*** Chip correctly deleted from heap\n";

    BadVirtualAnimal *dick = new Dog{"Dick", "Douglas Adams"};
    std::cout << dick->full_name() << '\n';
    // !!! warning, undefined behavior! Do not expect Dog dtor being invoked !!!
    delete dick;
    std::cout << "*** Dick wrongly deleted from heap\n";
}
