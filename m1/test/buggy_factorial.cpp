/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * test
 */
#include "buggy_factorial.h"

int factorial(int number)
{
    return number <= 1 ? number : factorial(number - 1) * number;
}
