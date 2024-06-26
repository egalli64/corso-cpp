/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * shared_ptr
 */
#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> shared_empty;
    if (!shared_empty)
    {
        std::cout << "The current shared ptr is empty\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }

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
