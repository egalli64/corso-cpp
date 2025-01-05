/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * assert c-style
 */
// uncomment next line to disable assert
// #define NDEBUG

#include <cassert>
#include <iostream>

void print(const char *text)
{
    // active only if NDEBUG is not defined
    assert(text != nullptr);

    std::cout << "Text is: " << text << '\n';
}

int main()
{
    print("hello");

    print(nullptr);
}
