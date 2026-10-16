#include <canup/canup.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Basic test", "[canup]")
{
  REQUIRE(add(21, 21) == 42);
}
