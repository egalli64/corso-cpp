/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * stdio - get character
 */
#include <cstdio>
#include <cstdlib>

int main()
{
    // 1. getc
    const char *filename = "s7.txt";
    FILE *fr = fopen(filename, "r");
    if (fr == NULL)
    {
        printf("Can't open file %s in read mode\n", filename);
        return EXIT_FAILURE;
    }

    printf("Reading char by char from %s:", filename);

    int c = ' ';
    while (c != EOF)
    {
        putchar(c);
        c = fgetc(fr);
    }
    putchar('\n');

    fclose(fr);

    // 2. getchar
    printf("Pass me a char: ");
    c = getchar();
    printf("I have got the character '%c'\n", c);
}
