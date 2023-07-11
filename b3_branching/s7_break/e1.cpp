/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * break
 */
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Please, enter a few arguments\n";
        return 0;
    }

    std::cout << "I'll stop earlier if I see an 'x' at the beginning of an argument\n";
    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == 'x')
        {
            break;
        }
        std::cout << i << ") " << argv[i] << '\n';
    }
    std::cout << "Done\n";
}
