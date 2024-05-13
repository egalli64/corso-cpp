/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * decorator
 */
#include <iostream>
#include <memory>

class Coffee
{
  public:
    virtual ~Coffee() = default;
    virtual std::string description() const = 0;
    virtual double price() const = 0;
};

std::ostream &operator<<(std::ostream &os, const Coffee &coffee)
{
    return os << coffee.description() << " (€" << coffee.price() << ") ";
}

class Espresso : public Coffee
{
  public:
    std::string description() const override
    {
        return "Espresso";
    }

    double price() const override
    {
        return 1.10;
    }
};

class CoffeeExtra : public Coffee
{
  protected:
    std::shared_ptr<Coffee> coffee_;

  public:
    CoffeeExtra(std::shared_ptr<Coffee> coffee) : coffee_{coffee}
    {
    }

    std::string description() const override
    {
        return coffee_->description();
    }

    double price() const override
    {
        return coffee_->price();
    }
};

class Milk : public CoffeeExtra
{
  public:
    Milk(std::shared_ptr<Coffee> coffee) : CoffeeExtra{coffee}
    {
    }

    std::string description() const override
    {
        return CoffeeExtra::description() + ", Milk";
    }

    double price() const override
    {
        return CoffeeExtra::price() + 0.30;
    }
};

class Cocoa : public CoffeeExtra
{
  public:
    Cocoa(std::shared_ptr<Coffee> coffee) : CoffeeExtra{coffee}
    {
    }

    std::string description() const override
    {
        return CoffeeExtra::description() + ", Cocoa";
    }

    double price() const override
    {
        return CoffeeExtra::price() + 0.50;
    }
};

int main()
{
    std::shared_ptr<Coffee> espresso = std::make_shared<Espresso>();
    std::cout << *espresso << '\n';

    std::shared_ptr<Coffee> milky = std::make_shared<Milk>(espresso);
    std::cout << *milky << '\n';

    std::shared_ptr<Coffee> chocky = std::make_shared<Cocoa>(milky);
    std::cout << *chocky << '\n';

    std::shared_ptr<Coffee> doubleChocky = std::make_shared<Cocoa>(chocky);
    std::cout << *doubleChocky << '\n';
}
