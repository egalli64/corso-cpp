/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: Private inheritance
 */
#include <iostream>

class Tail
{
  private:
    int count_;

  public:
    Tail(int count) : count_(count)
    {
    }

    void wag(const std::string &name) const
    {
        std::cout << name << ": ";
        for (int i = 0; i < count_; ++i)
        {
            std::cout << "wag";
        }
        std::cout << '\n';
    }
};

// Dog has-a Tail
class Dog : private Tail
{
  private:
    std::string name_;

  public:
    Dog(const std::string &name, int count) : Tail(count), name_(name)
    {
    }

    void bark()
    {
        std::cout << name_ << ": bark!\n";
        wag(name_);
    }
};

int main()
{
    Dog tom{"Tom", 3};
    tom.bark();
    // Tail methods are not part of the dog interface
    // tom.wag();
}
