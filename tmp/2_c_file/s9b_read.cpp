/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * stdio - fread
 */
#include <cstdio>
#include <cstdlib>

int main()
{
    size_t sz = 10;
    int data[10];

    const char *filename = "s9.bin";
    FILE *fr = fopen(filename, "rb");
    if (fr == NULL)
    {
        printf("Can't open file %s in read binary mode\n", filename);
        return EXIT_FAILURE;
    }

    int count = fread(data, sizeof(int), sz, fr);
    fclose(fr);

    printf("The %d values read from %s are: ", count, filename);
    for (int i = 0; i < count; ++i)
    {
        printf("%d ", data[i]);
    }
    putchar('\n');
}
