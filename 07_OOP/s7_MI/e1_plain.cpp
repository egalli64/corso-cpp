/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: MI
 */
#include <iostream>

class Animal
{
  private:
    std::string name_;

  public:
    Animal(const std::string &name) : name_(name)
    {
        std::cout << "Animal ctor for " << name << '\n';
    }

    ~Animal()
    {
        std::cout << "Animal dtor for " << name_ << '\n';
    }

    const std::string &name() const
    {
        return name_;
    }
};

class Player
{
  private:
    std::string game_;

  public:
    Player(const std::string &game) : game_(game)
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

class Dog : public Animal, Player
{
  public:
    Dog(const std::string &name, const std::string &game) : Animal(name), Player(game)
    {
        std::cout << "Dog ctor" << '\n';
    }

    ~Dog()
    {
        std::cout << "Dog dtor" << '\n';
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
