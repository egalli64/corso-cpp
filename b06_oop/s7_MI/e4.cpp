/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Solving MI DDD problem by virtual inheritance
 */
#include <iostream>

// virtual base class
class Actor
{
  private:
    std::string name_;

  public:
    Actor()
    {
        std::cout << "Actor default ctor" << '\n';
    }

    Actor(const std::string &name) : name_(name)
    {
        std::cout << "Actor ctor for " << name << '\n';
    }

    virtual ~Actor()
    {
        std::cout << "Actor dtor for " << name_ << '\n';
    }

    const std::string &name() const
    {
        return name_;
    }
};

class Animal : virtual public Actor
{
    int age_;

  public:
    Animal()
    {
        std::cout << "Animal default ctor" << '\n';
    }

    Animal(const std::string &name) : Actor(name)
    {
        std::cout << "Animal ctor for " << name << '\n';
    }
    ~Animal()
    {
        std::cout << "Animal dtor" << '\n';
    }
};

class Player : virtual public Actor
{
  private:
    std::string game_;

  public:
    Player(const std::string &game) : game_(game)
    {
        std::cout << "Player ctor for " << game << '\n';
    }

    Player(const std::string &name, const std::string &game) : Actor(name), game_(game)
    {
        std::cout << "Player ctor for " << name << ", " << game << '\n';
    }

    ~Player()
    {
        std::cout << "Player dtor for " << game_ << '\n';
    }

    const std::string &game() const
    {
        return game_;
    }
};

class Dog : public Animal, Player
{
  public:
    // The diamond problem is solved from below
    Dog(const std::string &name, const std::string &game) : Animal(), Player(game), Actor(name)
    {
        std::cout << "Dog ctor" << '\n';
    }

    void message()
    {
        std::cout << name() << " likes playing " << game() << '\n';
    }
};

int main()
{
    Dog tom{"Tom", "chess"};
    tom.message();
}
