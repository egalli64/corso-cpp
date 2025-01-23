/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: shared_ptr
 */
#include "../Thing.h"
#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<Thing> sp = std::make_shared<Thing>(42);

    if (sp.unique())
    {
        // a second shared ptr on the same object
        std::shared_ptr<Thing> sp2{sp};
        std::cout << "A new shared ptr created by copy just increase the count\n";
        std::cout << "The use count is set to " << sp.use_count() << '\n';
        if (!sp.unique())
        {
            std::cout << "There are more owners for the same resource!\n";
        }
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    std::cout << "The second shared ptr went out of scope, use count is set to " << sp.use_count() << '\n';
    std::cout << "The last shared ptr exiting of scope causes the resource destruction\n";
}
