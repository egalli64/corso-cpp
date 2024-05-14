/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * stdio - fgets
 */
#include <cstdio>
#include <cstdlib>

int main()
{
    const size_t sz = 4;
    const size_t maxlen = 7;
    char messages[sz][maxlen];

    const char *filename = "s8.txt";
    FILE *fr = fopen(filename, "r");
    if (fr == NULL)
    {
        printf("Can't open file %s in read mode\n", filename);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < sz; ++i)
    {
        fgets(messages[i], maxlen, fr);
    }
    fclose(fr);

    puts("Output the strings to the console:");
    for (int i = 0; i < sz; ++i)
    {
        puts(messages[i]);
    }
}
