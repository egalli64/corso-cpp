/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * final class
 */
#include <iostream>

// A final class
class Animal final
{
private:
    std::string name_;

public:
    Animal(const std::string &name) : name_(name) {}

    const std::string &name() const { return name_; }
};

// can't extend a final class
// class Dog : public Animal {};

int main()
{
    Animal tom{"Tom"};
    std::cout << tom.name() << '\n';
}
