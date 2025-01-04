/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * parameter - by constant reference
 */
#include <iostream>
#include <string>

void unsafeHello(std::string &name)
{
    std::cout << "Hello " << name << "!\n";
    name[0] += 1;
}

void saferHello(const std::string &name)
{
    std::cout << "Hello " << name << "!\n";
    // won't compile: expression must be a modifiable lvalue
    // name[0] += 1;
}

int main()
{
    std::string bob = "Bob";
    unsafeHello(bob);
    std::cout << "Bob now is " << bob << '\n';

    std::string tom = "Tom";
    saferHello(tom);
}
