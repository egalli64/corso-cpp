/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * catch all
 */
#include <iostream>
using namespace std;

void risky()
{
    throw "Not yet implemented";
}

int main()
{
    try
    {
        risky();
    }
    catch (...)
    {
        cout << "Something went wrong\n";
    }

    cout << "Bye\n";
}
