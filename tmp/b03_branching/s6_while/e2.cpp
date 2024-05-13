/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * do while
 */
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << argv[0] << " has no parameters" << '\n';
    }
    else
    {
        std::cout << "The parameters:" << '\n';
        int i{1};
        do
        {
            std::cout << i << ") " << argv[i] << '\n';
            i += 1;
        } while (i < argc);
    }
}
