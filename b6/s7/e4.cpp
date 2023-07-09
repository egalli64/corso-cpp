/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Solving MI DDD problem by virtual inheritance
 */
#include <iostream>
using namespace std;

// virtual base class
class Actor
{
private:
    string name_;

public:
    Actor()
    {
        cout << "Actor default ctor" << '\n';
    }

    Actor(const string &name) : name_(name)
    {
        cout << "Actor ctor for " << name << '\n';
    }

    virtual ~Actor() { cout << "Actor dtor for " << name_ << '\n'; }

    const string &name() const { return name_; }
};

class Animal : virtual public Actor
{
    int age_;

public:
    Animal()
    {
        cout << "Animal default ctor" << '\n';
    }

    Animal(const string &name) : Actor(name)
    {
        cout << "Animal ctor for " << name << '\n';
    }
    ~Animal() { cout << "Animal dtor" << '\n'; }
};

class Player : virtual public Actor
{
private:
    string game_;

public:
    Player(const string &game) : game_(game)
    {
        cout << "Player ctor for " << game << '\n';
    }

    Player(const string &name, const string &game) : Actor(name), game_(game)
    {
        cout << "Player ctor for " << name << ", " << game << '\n';
    }

    ~Player() { cout << "Player dtor for " << game_ << '\n'; }

    const string &game() const { return game_; }
};

class Dog : public Animal, Player
{
public:
    // The diamond problem is solved from below
    Dog(const string &name, const string &game) : Animal(), Player(game), Actor(name)
    {
        cout << "Dog ctor" << '\n';
    }

    void message()
    {
        cout << name() << " likes playing " << game() << '\n';
    }
};

int main()
{
    Dog tom{"Tom", "chess"};
    tom.message();
}
