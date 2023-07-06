/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * by constant pointer
 */
#include <iostream>
using namespace std;

void unsafeHello(char *name)
{
    cout << "Hello " << name << "!\n";
    name[0] += 1;
}

void saferHello(const char *name)
{
    cout << "Hello " << name << "!\n";
    //    name[0] += 1; // can't change!
}

int main()
{
    char bob[]{"Bob"};
    unsafeHello(bob);
    cout << "Bob now is " << bob << '\n';

    char tom[]{"Tom"};
    saferHello(tom);
}
