/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * A simple class
 */
#ifndef CORSO_CPP_7_OOP_POLY_OTHER
#define CORSO_CPP_7_OOP_POLY_OTHER

/**
 * @brief Other is not a Base
 * @note to be target of dynamic_cast must to be polymorphic
 */
struct Other
{
    /**
     * @brief dtor
     */
    virtual ~Other()
    {
    }
};

#endif // CORSO_CPP_7_OOP_POLY_OTHER
