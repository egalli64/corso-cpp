/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * namespace - anonymous
 */
#include <iostream>

namespace
{
/**
 * @brief being in an anonymous namespace, it is visible only in this file
 */
void f()
{
    std::cout << "Hello\n";
}
} // namespace

/**
 * @brief being static, it is visible only in this file
 */
static void g()
{
    std::cout << "Hello\n";
}

/**
 * @brief using names visible only in the current file
 */
int main()
{
    f();
    g();
}
