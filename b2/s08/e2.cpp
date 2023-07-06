/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * nullptr
 */
#include <iostream>
using namespace std;

int main()
{
    cout << "Null pointer\n\n";

    int *ptr = nullptr;
    cout << "An unused pointer: " << ptr << '\n';
    cout << "A null pointer can't be dereferenced ... " << '\n';
    // Segmentation fault
    // cout << *ptr << '\n';
}
