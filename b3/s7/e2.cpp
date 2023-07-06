/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * continue
 */
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Please, enter a few arguments\n";
    }
    else
    {
        cout << "Arguments NOT starting with an 'x'\n";
        for (int i = 1; i < argc; ++i)
        {
            if (argv[i][0] == 'x')
            {
                continue;
            }
            cout << i << ") " << argv[i] << '\n';
        }
        cout << "Done\n";
    }
}
