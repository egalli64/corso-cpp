/*
 * Corso C++ - https://github.com/egalli64/corso-cpp/a7
 *
 * stdio - open / close
 */
#include <cstdio>
#include <iostream>

int main()
{
    const char *filename = "hello.txt";
    FILE *fr = fopen(filename, "r");

    if (fr == NULL)
    {
        std::cout << "Can't open file " << filename << '\n';
    }
    else
    {
        std::cout << "Closing file " << filename << '\n';
        fclose(fr);
    }
}