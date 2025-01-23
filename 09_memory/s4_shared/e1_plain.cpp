/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: shared_ptr
 */
#include <iostream>
#include <memory>

int main()
{
    // check a shared ptr for emptiness
    std::shared_ptr<int> spEmpty{};
    if (!spEmpty)
    {
        std::cout << "The current shared ptr is empty\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

    // check a shared ptr for containing a valid pointer
    std::shared_ptr<int> sp{new int{42}};
    if (sp)
    {
        std::cout << "The current shared ptr is _not_ empty\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }
}
