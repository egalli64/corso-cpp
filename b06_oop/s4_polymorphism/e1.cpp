/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * virtual method
 */
#include <iostream>

class Animal
{
private:
    std::string name_;

public:
    Animal(const std::string &name) : name_(name) {}

    // it is not virtual, not meant for overriding
    std::string name() const { return "Animal " + name_; }
};

class NonPolimorphicDog : public Animal
{
private:
    std::string owner_;

public:
    NonPolimorphicDog(const std::string &name, const std::string &owner) : Animal(name), owner_(owner) {}

    // it is _not_ an override!
    std::string name() const { return Animal::name() + " owned by " + owner_; }
};

int main()
{
    Animal tom{"Tom"};
    std::cout << tom.name() << '\n';

    NonPolimorphicDog bob{"Bob", "Robert Smith"};
    std::cout << bob.name() << '\n';

    std::cout << "Looping on the animals in a NON polimorphic way\n";
    Animal *animals[] = {&tom, &bob};
    for (Animal *pa : animals)
    {
        // name() is NOT virtual in this example!
        std::cout << pa->name() << '\n';
    }
}
