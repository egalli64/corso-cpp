/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * slicing
 */
#include <iostream>

/**
 * @brief a base class
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
     * @brief meant to be overwritten
     */
    virtual std::string name() const
    {
        return name_;
    }

    /**
     * @brief virtual dtor
     */
    ~Animal()
    {
    }
};

/**
 * @brief PolimorphicDog IS-An Animal, polimorphic in name()
 */
class PolimorphicDog : public Animal
{
  private:
    std::string owner_;

  public:
    /**
     * @brief ctor
     */
    PolimorphicDog(const std::string &name, const std::string &owner) : Animal(name), owner_(owner)
    {
    }

    /**
     * @brief gives a different meaning to name() for dogs
     */
    std::string name() const override
    {
        return Animal::name() + " owned by " + owner_;
    }
};

/**
 * @brief passing an object by value is rarely a good idea
 * @param a the Animal - expect slicing here!
 */
void bad_idea(Animal a)
{
    std::cout << "Animal passed by value (slicing!): " << a.name() << '\n';
}

/**
 * @brief passing an object by const ref is the norm
 * @param a the Animal - in the Liskov sense
 */
void normal(const Animal &a)
{
    std::cout << "Animal passed by const reference: " << a.name() << '\n';
}

/**
 * @brief passing an object by ptr is OK, but less common in modern C++
 * @param a the Animal - in the Liskov sense
 */
void by_ptr(const Animal *a)
{
    if (a == nullptr)
    {
        std::cout << "Instead of an animal I've got a nullptr!\n";
    }
    else
    {
        std::cout << "Animal passed by const ptr: " << a->name() << '\n';
    }
}

int main()
{
    Animal npas[] = {Animal{"Tom"}, PolimorphicDog{"Bob", "Robert Smith"}};
    std::cout << "An array of object leads to the slicing problem!" << '\n';
    for (const Animal &a : npas)
    {
        std::cout << a.name() << '\n';
    }

    Animal tom{"Tom"};
    std::cout << "An animal: " << tom.name() << '\n';

    PolimorphicDog bob{"Bob", "Robert Smith"};
    std::cout << "A polimorphic dog: " << bob.name() << '\n';

    bad_idea(bob);
    normal(bob);
    by_ptr(&bob);

    std::cout << "An array of pointers is not affected by slicing" << '\n';
    Animal *animals[] = {&tom, &bob};
    for (Animal *pa : animals)
    {
        std::cout << pa->name() << '\n';
    }

    bad_idea(*animals[1]);
    normal(*animals[1]);
    by_ptr(animals[1]);
}
