/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * do while
 */
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << argv[0] << " has no parameters" << '\n';
    }
    else
    {
        cout << "The parameters:" << '\n';
        int i = 1;
        do
        {
            cout << i << ") " << argv[i] << '\n';
            i += 1;
        } while (i < argc);
    }
}
