/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * virtual method
 */
#include <iostream>
using namespace std;

class Animal
{
private:
    string name_;

public:
    Animal(const string &name) : name_(name) {}

    string name() const { return "Animal " + name_; }
};

class NonPolimorphicDog : public Animal
{
private:
    string owner_;

public:
    NonPolimorphicDog(const string &name, const string &owner) : Animal(name), owner_(owner) {}

    string name() const { return Animal::name() + " owned by " + owner_; }
};

int main()
{
    Animal tom{"Tom"};
    cout << tom.name() << '\n';

    NonPolimorphicDog bob{"Bob", "Robert Smith"};
    cout << bob.name() << '\n';

    cout << "Looping on the animals in a NON polimorphic way\n";
    Animal *animals[] = {&tom, &bob};
    for (Animal *pa : animals)
    {
        // name() is NOT virtual in this example!
        cout << pa->name() << '\n';
    }
}
