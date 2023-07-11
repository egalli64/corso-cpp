#ifndef CORSO_CPP_B9_MEMORY_THING_EXT
#define CORSO_CPP_B9_MEMORY_THING_EXT
#include "Thing.h"

class ThingExt : public Thing
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

#endif // CORSO_CPP_B9_MEMORY_THING_EXT
