/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * virtual dtor (missing!)
 */
#include <iostream>
using namespace std;

// Bad virtual class, the dtor is not virtual!
class BadVirtualAnimal
{
private:
    string name_;

public:
    BadVirtualAnimal(const string &name) : name_(name)
    {
        cout << "BadVirtualAnimal ctor " << name << '\n';
    }

    // it should be virtual!
    ~BadVirtualAnimal() { cout << "BadVirtualAnimal dtor for " << name_ << '\n'; }

    const string &name() const { return name_; }
    virtual string fullName() const = 0;
};

class Dog : public BadVirtualAnimal
{
private:
    string owner_;

public:
    Dog(const string &name, const string &owner) : BadVirtualAnimal(name), owner_(owner)
    {
        cout << "Dog ctor " << owner << '\n';
    }

    ~Dog() { cout << "Dog dtor, owner " << owner_ << '\n'; }

    string fullName() const override
    {
        return BadVirtualAnimal::name() + " owned by " + owner_;
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

    BadVirtualAnimal *dick = new Dog{"Dick", "Douglas Adams"};
    cout << dick->fullName() << '\n';
    // The Dog dtor invocation usually is missing!
    delete dick;
}
