#include <catch2/catch_test_macros.hpp>


int add(int x, int y)
{
    return x + y;
}

TEST_CASE("Sum should be 10") {
    REQUIRE(add(5, 5) == 10);
}

TEST_CASE("Sum should not be 10") {
    REQUIRE(add(5, 15) != 10);
}


