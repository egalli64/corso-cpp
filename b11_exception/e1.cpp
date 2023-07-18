/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * assert c-style
 */
// comment next line to enable assert
// #define NDEBUG

#include <cassert>
#include <iostream>

void print(const char *text)
{
    assert(text != nullptr);

    std::cout << "Text is: " << text << '\n';
}

int main()
{
    print("hello");

    print(nullptr);
}
