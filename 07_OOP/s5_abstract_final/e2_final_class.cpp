/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * final class
 */
#include <iostream>

// A final class
/**
 * @brief
 */
class Animal final
{
  private:
    std::string name_;

  public:
    /**
     * @brief ctor
     */
    Animal(const std::string &name) : name_(name)
    {
    }

    /**
     * @brief name getter
     */
    const std::string &name() const
    {
        return name_;
    }
};

// can't extend a final class
// class Dog : public Animal {};

int main()
{
    Animal tom{"Tom"};
    std::cout << tom.name() << '\n';
}
