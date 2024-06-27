/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * pure virtual / final method
 */
#include <iostream>

/**
 * @brief An abstract class
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
    virtual std::string full_name() = 0;
};

/**
 * @brief Dog IS-A concrete Animal
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
     * @brief concrete full name, can't be overridden
     */
    std::string full_name() override final
    {
        return Animal::name() + " owned by " + owner_;
    }
};

/**
 * @brief Poodle IS-A Dog, can't be extended
 */
class Poodle final : public Dog
{
  public:
    /**
     * @brief ctor
     */
    Poodle(const std::string &name, const std::string &owner) : Dog(name, owner)
    {
    }

    // can't override a final method
    // std::string full_name() override { return "Poodle " + Dog::full_name(); }
};

int main()
{
    Dog bob{"Bob", "Robert Smith"};
    std::cout << bob.full_name() << '\n';

    Poodle tom{"Tom", "Thomas Benson"};
    std::cout << tom.full_name() << '\n';
}
