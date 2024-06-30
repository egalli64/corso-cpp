/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Private inheritance
 */
#include <iostream>

/**
 * @brief a class that could be derived from
 */
class Tail
{
  private:
    int count_;

  public:
    /**
     * @brief ctor
     */
    Tail(int count) : count_{count}
    {
    }

    /**
     * @brief dtor
     */
    virtual ~Tail()
    {
    }

    /**
     * @brief a method
     */
    void wag() const
    {
        for (int i = 0; i < count_; ++i)
        {
            std::cout << "wag ";
        }
        std::cout << '\n';
    }
};

/**
 * @brief Dog HAS-A Tail
 */
class Dog : private Tail
{
  private:
    const std::string name_;

  public:
    /**
     * @brief ctor
     */
    Dog(const std::string &name, int count) : Tail(count), name_(name)
    {
    }

    /**
     * @brief a method that uses its composed tail object
     */
    void bark()
    {
        std::cout << name_ << ": bark! ";
        wag();
    }
};

int main()
{
    Dog tom{"Tom", 3};
    tom.bark();
    // Tail methods are not part of the dog interface
    // tom.wag();
}
