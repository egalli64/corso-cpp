/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * test
 */
#include "buggy_factorial.h"
#include "doctest.h"

TEST_CASE("factorial")
{
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3'628'800);
}
