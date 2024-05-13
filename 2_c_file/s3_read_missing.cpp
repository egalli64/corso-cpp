/*
 * Corso C++ - https://github.com/egalli64/corso-cpp/a7
 *
 * stdio - open / close
 */
#include <cstdio>
#include <iostream>

int main()
{
    const char *filename = "missing.xyz";
    // Can't open in read mode a non-existing file
    FILE *fr = fopen(filename, "r");

    if (fr == NULL)
    {
        std::cout << "Can't open file " << filename << '\n';
    }
    else
    {
        // Only a non-NULL FILE could be closed
        fclose(fr);
    }
}