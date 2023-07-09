/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * virtual dtor (fix!)
 */
#include <iostream>
using namespace std;

class Animal
{
private:
    string name_;

public:
    Animal(const string &name) : name_(name) {}
    // virtual, as it should be
    virtual ~Animal() { cout << "Animal dtor for " << name_ << '\n'; }

    const string &name() const { return name_; }
    virtual string fullName() const = 0;
};

class Dog : public Animal
{
private:
    string owner_;

public:
    Dog(const string &name, const string &owner) : Animal(name), owner_(owner) {}
    ~Dog() { cout << "Dog dtor, owner " << owner_ << '\n'; }

    string fullName() const override
    {
        return Animal::name() + " owned by " + owner_;
    }
};

void bobFunction()
{
    Dog bob{"Bob", "Robert Smith"};
    cout << bob.fullName() << '\n';
}

int main()
{
    bobFunction();

    Dog *chip = new Dog{"Chip", "Charlie Parker"};
    cout << chip->fullName() << '\n';
    delete chip;

    Animal *dick = new Dog{"Dick", "Douglas Adams"};
    cout << dick->fullName() << '\n';
    // both dtor correctly called
    delete dick;
}
