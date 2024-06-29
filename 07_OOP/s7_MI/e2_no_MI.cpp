/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Simple hierarchy, no MI
 */
#include <iostream>

/**
 * @brief a base class
 */
class Actor
{
  private:
    const std::string name_;

  public:
    /**
     * @brief ctor
     */
    Actor(const std::string &name) : name_{name}
    {
        std::cout << "Actor ctor for " << name << '\n';
    }

    /**
     * @brief dtor
     */
    virtual ~Actor()
    {
        std::cout << "Actor dtor for " << name_ << '\n';
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
 * @brief a class in the middle level Animal IS-An Actor
 */
class Animal : public Actor
{
  public:
    /**
     * @brief ctor
     */
    Animal(const std::string &name) : Actor{name}
    {
        std::cout << "Animal ctor for " << name << '\n';
    }

    /**
     * @brief dtor
     */
    ~Animal() override
    {
        std::cout << "Animal dtor" << '\n';
    }
};

/**
 * @brief another class in the middle level Player IS-An Actor
 */
class Player : public Actor
{
  private:
    const std::string game_;

  public:
    /**
     * @brief ctor
     */
    Player(const std::string &name, const std::string &game) : Actor{name}, game_{game}
    {
        std::cout << "Player ctor for " << game << '\n';
    }

    /**
     * @brief dtor
     */
    ~Player() override
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
 * @brief a class in the lower lever
 */
class Dog : public Player
{
  public:
    /**
     * @brief ctor
     */
    Dog(const std::string &name, const std::string &game) : Player{name, game}
    {
        std::cout << "Dog ctor\n";
    }

    /**
     * @brief a Dog Player method
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
    std::cout << " ... but Tom should be an animal, too!" << '\n';
}
