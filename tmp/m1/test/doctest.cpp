/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * test
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "buggy_factorial.h"
#include "buggy_negator.h"
#include <climits>
#include <iostream>

TEST_CASE("check vs require")
{
    CHECK(0 == 1);
    REQUIRE(0 == 1);
    CHECK(0 == 2);
}

TEST_CASE("subcase")
{
    std::cout << "Root level\n";

    SUBCASE("subcase 1")
    {
        std::cout << "Subcase 1\n";
    }

    SUBCASE("subcase 2")
    {
        std::cout << "Subcase 2\n";
    }
}
