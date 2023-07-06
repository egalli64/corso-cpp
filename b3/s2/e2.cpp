/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * if - else
 */
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    cout << "The caller ";
    if (argc == 1)
    {
        cout << "didn't pass any argument\n";
    }
    else
    {
        cout << "passed at least a argument\n";
    }
    cout << "Bye\n";
}
