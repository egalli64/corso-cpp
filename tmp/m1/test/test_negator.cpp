/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * test
 */
#include "doctest.h"

#include "buggy_negator.h"
#include <climits>

TEST_CASE("negator")
{
    CHECK(negator(0) == 0);
    CHECK(negator(42) == -42);
    CHECK(negator(-63) == 63);
    CHECK(negator(INT_MIN) == INT_MIN);
}
