/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * make
 */
#include "other.h"
#include "sub/another.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello from main\n";
    other_hello("Other hello");
    another_hello("Another hello");
}
