/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * A simple class
 */
#ifndef CORSO_CPP_7_OOP_INHERITANCE_TAIL
#define CORSO_CPP_7_OOP_INHERITANCE_TAIL

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
        std::cout << "Tail ctor, count is " << count_ << '\n';
    }

    /**
     * @brief dtor
     */
    virtual ~Tail()
    {
        std::cout << "Tail dtor, count is " << count_ << '\n';
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

#endif // CORSO_CPP_7_OOP_INHERITANCE_TAIL
