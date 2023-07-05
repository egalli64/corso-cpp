#include <iostream>
using namespace std;

class Animal {
private:
    string name_;
public:
    Animal(const string& name) : name_(name) {}
    virtual ~Animal() { cout << "Dtor for " << name_ << '\n'; }

    const string& name() const { return name_; }
    virtual string fullName() const = 0;
};

class Dog : public Animal {
private:
    string owner_;
public:
    Dog(const string& name, const string& owner) : Animal(name), owner_(owner) {}
    ~Dog() { cout << "Dtor for dog owned by " << owner_ << '\n'; }

    string fullName() const override {
        return Animal::name() + " owned by " + owner_;
    }
};

void bobFunction() {
    Dog bob("Bob", "Robert Smith");
    cout << bob.fullName() << '\n';
}

int main() {
    bobFunction();

    Dog* chip = new Dog("Chip", "Charlie Parker");
    cout << chip->fullName() << '\n';
    delete chip;

    Animal* dick = new Dog("Dick", "Douglas Adams");
    cout << dick->fullName() << '\n';
    delete dick;
}
