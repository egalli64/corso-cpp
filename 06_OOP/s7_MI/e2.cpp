/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Simple hierarchy, no MI
 */
#include <iostream>

class Actor
{
  private:
    std::string name_;

  public:
    Actor(const std::string &name) : name_(name)
    {
        std::cout << "Actor ctor for " << name << '\n';
    }
    ~Actor()
    {
        std::cout << "Actor dtor for " << name_ << '\n';
    }

    const std::string &name() const
    {
        return name_;
    }
};

class Animal : public Actor
{
  public:
    Animal(const std::string &name) : Actor(name)
    {
        std::cout << "Animal ctor for " << name << '\n';
    }
    ~Animal()
    {
        std::cout << "Animal dtor" << '\n';
    }
};

class Player : public Actor
{
  private:
    std::string game_;

  public:
    Player(const std::string &name, const std::string &game) : Actor(name), game_(game)
    {
        std::cout << "Player ctor for " << game << '\n';
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

class Dog : public Player
{
  public:
    Dog(const std::string &name, const std::string &game) : Player(name, game)
    {
        std::cout << "Dog ctor\n";
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
    std::cout << " ... but Tom should be an animal, too!" << '\n';
}
