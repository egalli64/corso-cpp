/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * auto return type
 */
#include <iostream>

namespace
{
/**
 * @brief a dubious function, it is too easy break the code in the future with a simple change
 *
 * @return a value whose type is deduced by the compiler
 */
auto answer()
{
    return 42;
}
} // namespace

int main()
{
    auto x = answer();
    std::cout << "The answer is " << x << '\n';
}
