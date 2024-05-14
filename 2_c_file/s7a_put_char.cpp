/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * stdio - put character
 */
#include <cstdio>

int main()
{
    // 1. fputc
    const char *filename = "s7.txt";
    FILE *fw = fopen(filename, "w");

    for (int c = 'a'; c <= 'z'; ++c)
    {
        fputc(c, fw);
    }

    fclose(fw);
    printf("See the result in the %s file\n", filename);

    // 2. putchar
    for (int c = 'a'; c <= 'z'; ++c)
    {
        putchar(c);
    }
    putchar('\n');
}
