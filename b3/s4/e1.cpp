/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Ternary operator ?:
 */
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    const char *name = argc > 1 ? argv[1] : "Unknown";
    cout << "Hello " << name << '!' << '\n';
}
