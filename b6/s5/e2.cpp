/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * final class
 */
#include <iostream>
using namespace std;

// A final class
class Animal final
{
private:
    string name_;

public:
    Animal(const string &name) : name_(name) {}

    const string &name() const { return name_; }
};

// can't extend a final class
// class Dog : public Animal {};

int main()
{
    Animal tom{"Tom"};
    cout << tom.name() << '\n';
}
