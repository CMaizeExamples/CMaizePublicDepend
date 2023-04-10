#include <catch2/catch_test_macros.hpp>

#include <cmaize_public_depend/cmaize_public_depend.hpp>

TEST_CASE("cmaize_public_depend") {
    SECTION("does_cmaize_public_depend_work") {
        REQUIRE(cmaize_public_depend::call_cmaize_public_depend() == 6);
    }
}
