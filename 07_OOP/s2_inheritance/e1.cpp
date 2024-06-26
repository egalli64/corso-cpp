/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * inheritance
 */
#include <iostream>

/**
 * @brief a simple base class
 */
class Animal
{
  private:
    const std::string name_;

  public:
    /**
     * @brief default ctor
     */
    Animal() : name_("Unkwnown"){};

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
};

/**
 * @brief put-to overload for Animal to ostream
 */
std::ostream &operator<<(std::ostream &os, const Animal &animal)
{
    return os << animal.name();
}

/**
 * @brief Dog IS-A Animal
 */
class Dog : public Animal
{
  private:
    const std::string owner_;

  public:
    /**
     * @brief default ctor, implicitly call Animal default ctor
     */
    Dog() : owner_("none")
    {
    }

    /**
     * @brief ctor, explicitly call Animal ctor
     */
    Dog(const std::string &name, const std::string &owner) : Animal(name), owner_(owner)
    {
    }

    /**
     * @brief owner getter
     */
    const std::string &owner() const
    {
        return owner_;
    }
};

/**
 * @brief put-to overload for Dog to ostream
 */
std::ostream &operator<<(std::ostream &os, Dog dog)
{
    return os << dog.name() << " owned by " << dog.owner();
}

int main()
{
    Animal tom{"Tom"};
    std::cout << tom << '\n';

    Dog bob{"Bob", "Robert Smith"};
    std::cout << bob << '\n';

    Dog x;
    std::cout << x << '\n';
}
