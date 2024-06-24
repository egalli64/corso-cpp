/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * assert c-style
 */
// uncomment next line to disable assert
// #define NDEBUG

#include <cassert>
#include <iostream>

namespace
{
/**
 * @brief a function with an assertion on its parameter
 * @param text a-cstring
 *
 * @note prerequisite: text should not be a nullptr
 */
void print(const char *text)
{
    // active only if NDEBUG is not defined
    assert(text != nullptr);

    std::cout << "Text is: " << text << '\n';
}
} // namespace

int main()
{
    print("hello");

    print(nullptr);
}
