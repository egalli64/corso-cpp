/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * stdio - fprintf / printf
 */
#include <cmath>
#include <cstdio>

int main()
{
    const char *filename = "s5.txt";

    // notice that "w" mode would overwrite an existing file!
    FILE *fw = fopen(filename, "w");

    int x = 42;

    fprintf(fw, "Writing an integer (%d), a floating point number (%.10f), ", x, M_PI);
    fprintf(fw, "a character (%c), and a string (%s)\n", x, filename);
    fclose(fw);

    printf("Check the result in %s\n", filename);
}