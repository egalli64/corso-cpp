/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: weak_ptr
 */
#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> sp = std::make_shared<int>(42);

    std::weak_ptr<int> wpEmpty;
    std::weak_ptr<int> wp{sp};
    std::weak_ptr<int> wp2 = {wp};

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
