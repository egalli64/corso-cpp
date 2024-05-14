/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * stdio - fscanf
 */
#include <cstdio>
#include <cstdlib>

int main()
{
    const char *filename = "s6.txt";
    FILE *fr = fopen(filename, "r");

    if (fr == NULL)
    {
        printf("Can't open file %s in read mode\n", filename);
        return EXIT_FAILURE;
    }

    int x;
    float pi;
    double e;
    char c;
    char info[21];

    fscanf(fr, "%d %f %lf %c %s", &x, &pi, &e, &c, info);
    fclose(fr);

    printf("The integer is %d\n", x);
    printf("The float is %f\n", pi);
    printf("The double is %f\n", e);
    printf("The char is %c\n", c);
    printf("The string is \"%s\"\n", info);
}
