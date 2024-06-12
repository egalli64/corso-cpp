/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * decorator
 */
#include <iostream>

class Warrior
{
  public:
    virtual void fight()
    {
        std::cout << "Fighting as a warrior\n";
    }

    virtual ~Warrior() = default;
};

class WarriorWizard final : public Warrior
{
  private:
    Warrior warrior_;

  public:
    WarriorWizard(Warrior warrior) : warrior_(warrior)
    {
        std::cout << "Now I am a warrior-wizard!\n";
    }

    void fight() override
    {
        std::cout << "Fighting as a warrior, but in a wizardish way\n";
    }

    Warrior extract()
    {
        return warrior_;
    }
};

int main()
{
    Warrior tom;
    tom.fight();

    // ...

    std::cout << "Something strange happens ...\n";
    WarriorWizard tom_plus(tom);
    tom_plus.fight();

    // ...

    std::cout << "After some time, the magic effect disappears\n";
    Warrior original_tom = tom_plus.extract();
    original_tom.fight();
}
