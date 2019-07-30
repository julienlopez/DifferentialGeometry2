#include <catch2/catch.hpp>

#include "comparison.hpp"
#include "derivative.hpp"

TEST_CASE("Derivative")
{

    SECTION("deriving a constant gives zero")
    {
        Expression exp(Constant{L"R"});
        const auto d = boost::apply_visitor(Derivative{}, exp);
        CHECK(areEqual(d, Value{0.}));
    }
}
