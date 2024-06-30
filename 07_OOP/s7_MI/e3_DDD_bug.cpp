/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * MI with DDD problem
 */
#include <iostream>

/**
 * @brief base class
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
 * @brief intermediate class - Animal IS-An Actor
 */
class Animal : public Actor
{
  public:
    /**
     * @brief ctor
     */
    Animal(const std::string &name) : Actor(name)
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
 * @brief intermediate class - Player IS-An Actor
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
 * @brief third level class - Dog IS-An Animal and IS-A Player
 */
class Dog : public Animal, Player
{
  public:
    /**
     * @brief ctor - name should be passed both to Animal and Player!
     * @bug a Dog is twice an Actor, once as Animal and once as Player ?!
     */
    Dog(const std::string &name, const std::string &game) : Animal{name}, Player{name, game}
    {
        std::cout << "Dog ctor" << '\n';
    }

    /**
     * @brief a method using the upper levels details
     */
    void message()
    {
        // ambiguous! name as animal or as player?
        // cout << name() << " likes playing " << game() << '\n';

        // explicitly choosing the "right" name
        std::cout << Player::name() << " likes playing " << game() << '\n';
    }
};

int main()
{
    Dog tom{"Tom", "chess"};
    std::cout << "*** Tom is created, notice the double call to Animal ctor!\n";
    tom.message();

    std::cout << "*** Tom is about to be deleted, notice the double call to Animal dtor!\n";
}
