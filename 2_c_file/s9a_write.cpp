/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * stdio - fwrite
 */
#include <cstdio>

int main()
{
    int data[]{4343, 8723, 7012, 4855, 1203, 1985, 3424};
    int sz = sizeof(data) / sizeof(int);

    const char *filename = "s9.bin";
    FILE *fw = fopen(filename, "w");
    int count = fwrite(data, sizeof(int), sz, fw);
    fclose(fw);

    printf("%d values have been stored in the %s file\n", count, filename);
}
