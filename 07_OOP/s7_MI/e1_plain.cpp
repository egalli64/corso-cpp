/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * MI
 */
#include <iostream>

/**
 * @brief a base class
 */
class Animal
{
  private:
    const std::string name_;

  public:
    /**
     * @brief ctor
     */
    Animal(const std::string &name) : name_{name}
    {
        std::cout << "Animal ctor for " << name << '\n';
    }

    /**
     * @brief dtor
     */
    virtual ~Animal()
    {
        std::cout << "Animal dtor for " << name_ << '\n';
    }

    /**
     * @brief getter
     */
    const std::string &name() const
    {
        return name_;
    }
};

/**
 * @brief another base class
 */
class Player
{
  private:
    const std::string game_;

  public:
    /**
     * @brief ctor
     */
    Player(const std::string &game) : game_(game)
    {
        std::cout << "Player ctor for " << game << '\n';
    }

    /**
     * @brief dtor
     */
    virtual ~Player()
    {
        std::cout << "Player dtor for " << game_ << '\n';
    }

    /**
     * @brief getter
     */
    const std::string &game() const
    {
        return game_;
    }
};

/**
 * @brief Dog IS-An Animal, and IS-A Player, too!
 */
class Dog : public Animal, Player
{
  public:
    /**
     * @brief ctor, create the internal objects from left to right
     */
    Dog(const std::string &name, const std::string &game) : Animal{name}, Player{game}
    {
        std::cout << "Dog ctor" << '\n';
    }

    /**
     * @brief dtor, pass the control to the upper level from right to left
     */
    ~Dog() override
    {
        std::cout << "Dog dtor" << '\n';
    }

    /**
     * @brief a method that uses both natures of the object
     */
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
