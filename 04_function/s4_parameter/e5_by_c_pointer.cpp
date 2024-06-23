/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by constant pointer
 */
#include <iostream>

namespace
{
/**
 * @brief use a non-const pointer only when strictly required
 *
 * @param name a mutable c-string
 */
void unsafeHello(char *name)
{
    std::cout << "Hello " << name << "!\n";
    name[0] += 1;
}

/**
 * @brief if the passed object has not to be changed prefer qualify the pointer as const
 *
 * @param name an immutable c-string
 */
void saferHello(const char *name)
{
    std::cout << "Hello " << name << "!\n";
    // won't compile
    // name[0] += 1;
}
} // namespace

int main()
{
    // setting a non-const char array from a const char*
    char bob[] = "Bob";
    unsafeHello(bob);
    std::cout << "Bob now is " << bob << '\n';

    // it would be more expressive to define tom as a const char*
    char tom[] = "Tom";
    saferHello(tom);
}
