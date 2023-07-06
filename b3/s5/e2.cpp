/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * for
 */
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    cout << argv[0] << " has " << argc - 1 << " parameters\n";
    for (int i = 1; i < argc; ++i)
    {
        cout << i << ") " << argv[i] << '\n';
    }
}
