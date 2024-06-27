/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * A simple class
 */
#ifndef CORSO_CPP_7_OOP_POLY_BASE
#define CORSO_CPP_7_OOP_POLY_BASE

/**
 * @brief base class
 * @note to be target of dynamic_cast must be polymorphic
 */
class Base
{
  public:
    /**
     * @brief dtor
     */
    virtual ~Base()
    {
    }
};

#endif // CORSO_CPP_7_OOP_POLY_BASE
