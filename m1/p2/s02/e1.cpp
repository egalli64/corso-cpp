#include <iostream>
using namespace std;

int main() {
    // a is declared as int, but not initialized
    int a;
    // when compiled with -Wall flag -> warning: access to uninitialized variable
    cout << "!!! BAD IDEA !!! " << a << '\n';

    a = 5; // a is initialized to 5
    cout << a << '\n';

    // variable definition preferred to split declaration and initialization
    int b = 7;
    cout << b << '\n';

    // assignment, changing value in a variable
    b = 42;
    cout << b << '\n';
}
