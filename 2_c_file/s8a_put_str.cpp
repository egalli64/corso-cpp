/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * stdio - fputs / puts
 */
#include <cstdio>

int main()
{
    size_t sz = 3;
    char messages[sz][6]{"one", "two", "three"};

    // 1. fputs
    const char *filename = "s8.txt";
    FILE *fw = fopen(filename, "w");

    for (int i = 0; i < sz; ++i)
    {
        fputs(messages[i], fw);
        fputc('\n', fw);
    }
    fputs("hello!", fw);

    fclose(fw);
    printf("See the result in the %s file\n", filename);

    // 2. puts adds a new-line at the end
    puts("Output the strings to the console:");
    for (int i = 0; i < sz; ++i)
    {
        puts(messages[i]);
    }
}
