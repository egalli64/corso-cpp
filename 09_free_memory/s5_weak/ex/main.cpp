/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * weak_ptr exercise
 */
#include "Node.h"

int main()
{
    auto a = std::make_shared<Node>(1);
    auto b = std::make_shared<Node>(2);
    auto c = std::make_shared<Node>(3);

    std::cout << *a << ", " << *b << ", " << *c << '\n';

    a->connect(b);
    b->connect(c);
    c->connect(a);

    std::cout << *a << ", " << *b << ", " << *c << '\n';
}