/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * slicing
 */
#include <iostream>

class Animal
{
private:
    std::string name_;

public:
    Animal(const std::string &name) : name_(name) {}

    virtual std::string name() const { return name_; }
};

class PolimorphicDog : public Animal
{
private:
    std::string owner_;

public:
    PolimorphicDog(const std::string &name, const std::string &owner) : Animal(name), owner_(owner) {}

    std::string name() const override
    {
        return Animal::name() + " owned by " + owner_;
    }
};

void badIdea(Animal byValue)
{
    std::cout << "Animal passed by value (slicing!): " << byValue.name() << '\n';
}

void normal(const Animal &byConstRef)
{
    std::cout << "Animal passed by const reference: " << byConstRef.name() << '\n';
}

void byPointer(const Animal *p)
{
    if (p == nullptr)
    {
        return;
    }
    std::cout << "Animal passed by const ptr: " << p->name() << '\n';
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

    badIdea(bob);
    normal(bob);
    byPointer(&bob);

    std::cout << "An array of pointers is not affected by slicing" << '\n';
    Animal *animals[] = {&tom, &bob};
    for (Animal *pa : animals)
    {
        std::cout << pa->name() << '\n';
    }

    badIdea(*animals[1]);
    normal(*animals[1]);
    byPointer(animals[1]);
}
