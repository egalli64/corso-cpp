/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * A simple class
 */
#ifndef CORSO_CPP_7_OOP_POLY_DERIVED
#define CORSO_CPP_7_OOP_POLY_DERIVED

#include "Base.hpp"
#include <iostream>

/**
 * @brief Derived IS-A Base
 */
class Derived : public Base
{
  private:
    const int x = 42;

  public:
    void f()
    {
        std::cout << "x is " << x << "\n";
    }
};

#endif // CORSO_CPP_7_OOP_POLY_DERIVED
