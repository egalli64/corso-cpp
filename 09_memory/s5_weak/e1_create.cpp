/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: weak_ptr
 */
#include <iostream>
#include <memory>

int main()
{
    // no use of weak ptr if there is no shared ptr around
    std::shared_ptr<int> sp = std::make_shared<int>(42);

    // an empty weak ptr
    std::weak_ptr<int> wpEmpty{};

    // a weak ptr directly associated to a shared ptr
    std::weak_ptr<int> wp{sp};

    // a weak ptr indirectly associated to a shared ptr (or empty)
    std::weak_ptr<int> wp2{wp};

    // won't compile
    // wp2 = nullptr;
    wp2.reset();

    if (wpEmpty.expired() && !wp.expired() && wp2.expired())
    {
        std::cout << "Only the weak pointer wp is not expired\n";
    }
    else
    {
        std::cout << "Unexpected!\n";
    }
}
