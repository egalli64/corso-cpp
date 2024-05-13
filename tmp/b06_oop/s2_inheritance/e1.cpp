/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * inheritance
 */
#include <iostream>

class Animal
{
  private:
    const std::string name_;

  public:
    Animal() : name_("Unkwnown"){};
    Animal(const std::string &name) : name_(name)
    {
    }

    const std::string &name() const
    {
        return name_;
    }
};

std::ostream &operator<<(std::ostream &os, const Animal &animal)
{
    return os << animal.name();
}

class Dog : public Animal
{
  private:
    const std::string owner_;

  public:
    Dog() : owner_("none")
    {
    }
    Dog(const std::string &name, const std::string &owner) : Animal(name), owner_(owner)
    {
    }

    const std::string &owner() const
    {
        return owner_;
    }
};

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
