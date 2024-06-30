/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Solving MI DDD problem by virtual inheritance
 */
#include <iostream>

/**
 * @brief virtual base class
 */
class Actor
{
  private:
    const std::string name_;

  public:
    /**
     * @brief default ctor
     * @note do not set the data members!
     */
    Actor()
    {
        std::cout << "Actor default ctor" << '\n';
    }

    /**
     * @brief ctor
     * @note set all the data members
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
 * @brief intermediate class - Animal IS-An Actor (virtually!)
 * @note it concurs in determining the virtuality of its base class!
 */
class Animal : virtual public Actor
{
    int age_;

  public:
    /**
     * @brief ctor
     */
    Animal(int age) : age_{age}
    {
        std::cout << "Animal ctor with age " << age_ << '\n';
    }

    /**
     * @brief ctor
     */
    Animal(const std::string &name, int age) : Actor{name}, age_{age}
    {
        std::cout << "Animal ctor for " << name << " aged " << age << '\n';
    }

    /**
     * @brief dtor
     */
    ~Animal() override
    {
        std::cout << "Animal dtor for " << name() << " aged " << age_ << '\n';
    }
};

/**
 * @brief intermediate class - Player IS-An Actor (virtually!)
 * @note it concurs in determining the virtuality of its base class!
 */
class Player : virtual public Actor
{
  private:
    std::string game_;

  public:
    /**
     * @brief ctor
     */
    Player(const std::string &game) : game_{game}
    {
        std::cout << "Player ctor for " << game << '\n';
    }

    /**
     * @brief ctor
     */
    Player(const std::string &name, const std::string &game) : Actor{name}, game_{game}
    {
        std::cout << "Player ctor for " << name << ", " << game << '\n';
    }

    /**
     * @brief dtor
     */
    ~Player() override
    {
        std::cout << "Player dtor for " << name() << ", " << game_ << '\n';
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
 * @note it starts the mechanim of virtual inheritance, extending two class that virtually derives from the same class!
 */
class Dog : public Animal, Player
{
  public:
    /**
     * @brief ctor - it is its responibility calling the top level class ctor!
     * @note The diamond problem is solved from below!
     */
    Dog(const std::string &name, const std::string &game) : Actor(name), Animal(5), Player(game)
    {
        std::cout << "Dog ctor" << '\n';
    }

    /**
     * @brief a method
     */
    void message()
    {
        std::cout << name() << " likes playing " << game() << '\n';
    }

    /**
     * @brief dtor
     */
    ~Dog() override
    {
        std::cout << "Dog dtor\n";
    }
};

int main()
{
    Dog tom{"Tom", "chess"};
    tom.message();

    Actor *bob = new Dog("Bob", "poker");
    std::cout << bob->name() << '\n';
    delete bob;
    std::cout << "---\n";
}
