/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by constant pointer
 */
#include <iostream>

namespace
{
void unsafeHello(char *name)
{
    std::cout << "Hello " << name << "!\n";
    name[0] += 1;
}

void saferHello(const char *name)
{
    std::cout << "Hello " << name << "!\n";
    // being const, can't change!
    // name[0] += 1;
}
} // namespace

int main()
{
    char *bob = "Bob";
    unsafeHello(bob);
    std::cout << "Bob now is " << bob << '\n';

    char *tom = "Tom";
    saferHello(tom);
}
