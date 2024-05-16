/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * stdio - scanf
 */
#include <cmath>
#include <cstdio>

int main()
{
    int x;

    printf("Pass me an integer: ");
    int check = scanf("%d", &x);
    if (check == 1)
    {
        printf("The integer is %d\n", x);
    }
    else
    {
        printf("I can't see an integer in your input!\n");
    }
}
