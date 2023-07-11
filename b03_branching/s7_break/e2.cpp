/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * continue
 */
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Please, enter a few arguments\n";
    }
    else
    {
        std::cout << "Arguments NOT starting with an 'x'\n";
        for (int i = 1; i < argc; ++i)
        {
            if (argv[i][0] == 'x')
            {
                continue;
            }
            std::cout << i << ") " << argv[i] << '\n';
        }
        std::cout << "Done\n";
    }
}
