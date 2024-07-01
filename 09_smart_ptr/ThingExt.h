/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * A simple derived class
 */
#ifndef CORSO_CPP_9_MEMORY_THING_EXT
#define CORSO_CPP_9_MEMORY_THING_EXT

#include "Thing.h"

class ThingExt final : public Thing
{
  public:
    ThingExt(int x) : Thing(x)
    {
        std::cout << "ThingExt ctor\n";
    }

    void hello() const override
    {
        std::cout << "ThingExt ";
        Thing::hello();
    }

    ~ThingExt()
    {
        std::cout << "ThingExt dtor\n";
    }
};

#endif // CORSO_CPP_9_MEMORY_THING_EXT
