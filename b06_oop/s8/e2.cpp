/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Protected inheritance
 */
#include <iostream>

class Tail
{
private:
    int count_;

public:
    Tail(int count) : count_(count) {}

    void wag(const std::string &name) const
    {
        std::cout << name << ": ";
        for (int i = 0; i < count_; ++i)
        {
            std::cout << "wag";
        }
        std::cout << '\n';
    }
};

// Dog has-a Tail, and shares its access to derived classes
class Dog : protected Tail
{
protected:
    std::string name_;

public:
    Dog(const std::string &name, int count) : Tail(count), name_(name) {}

    void bark()
    {
        std::cout << name_ << ": bark!\n";
        wag(name_);
    }

    virtual void eat()
    {
        std::cout << name_ << ": eat\n";
    }
};

class Poodle : public Dog
{
public:
    Poodle(const std::string &name) : Dog(name, 2) {}

    void eat() override
    {
        std::cout << name_ << ": eat\n";
        wag(name_);
    }
};

int main()
{
    Dog tom{"Tom", 3};
    tom.bark();
    tom.eat();

    Poodle bob{"Bob"};
    bob.bark();
    bob.eat();
}
