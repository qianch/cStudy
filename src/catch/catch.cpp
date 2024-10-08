#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include <iostream>

void test(int n)
{
    if (n == 42)
    {
        return;
    }
    throw std::runtime_error("not the answer");
}

TEST_CASE("case1", "[case1]")
{
    INFO("testing");
    CHECK(1 + 1 == 2);
    CHECK_THROWS_AS(
        test(41), std::runtime_error);
    CHECK_NOTHROW(test(42));

    int expected = 5;
    CHECK(2 + 2 == expected);
}

TEST_CASE("case2", "[case2]")
{
    CHECK(1 == 1);
    CHECK(1 == 2);
}
