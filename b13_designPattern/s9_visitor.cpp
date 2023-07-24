/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * visitor
 */
#include <iostream>
#include <memory>
#include <vector>

class Dog;
class Cat;

class PetVisitor
{
  public:
    virtual void visit(Dog &) = 0;
    virtual void visit(Cat &) = 0;
};

class FeedingVisitor : public PetVisitor
{
  public:
    void visit(Dog &) override
    {
        std::cout << "Feeding dog\n";
    }

    void visit(Cat &) override
    {
        std::cout << "Feeding cat\n";
    }
};

class HealthCheckVisitor : public PetVisitor
{
  public:
    void visit(Dog &) override
    {
        std::cout << "Checking dog's health\n";
    }

    void visit(Cat &) override
    {
        std::cout << "Checking cat's health\n";
    }
};

class Pet
{
  public:
    virtual void accept(PetVisitor &visitor) = 0;
};

class Dog : public Pet
{
  public:
    void accept(PetVisitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class Cat : public Pet
{
  public:
    void accept(PetVisitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class PetHotel
{
  private:
    std::vector<std::shared_ptr<Pet>> pets;

  public:
    void addAnimal(std::shared_ptr<Pet> animal)
    {
        pets.push_back(animal);
    }

    void performOperation(PetVisitor &visitor)
    {
        for (const auto &animal : pets)
        {
            animal->accept(visitor);
        }
    }
};

int main()
{
    PetHotel hotel;
    hotel.addAnimal(std::make_shared<Dog>());
    hotel.addAnimal(std::make_shared<Cat>());

    FeedingVisitor feeder;
    HealthCheckVisitor healthChecker;

    hotel.performOperation(feeder);
    hotel.performOperation(healthChecker);
}
