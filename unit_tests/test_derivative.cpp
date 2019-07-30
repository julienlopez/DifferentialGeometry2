#include <catch2/catch.hpp>

#include "comparison.hpp"
#include "derivative.hpp"

TEST_CASE("Derivative")
{

    SECTION("deriving a constant gives zero")
    {
        Expression exp(Constant{L"R"});
        const auto d = boost::apply_visitor(Derivative{L"x"}, exp);
        CHECK(areEqual(d, Value{0.}));
    }

    SECTION("deriving a value gives zero")
    {
        Expression exp(Value{25});
        const auto d = boost::apply_visitor(Derivative{L"x"}, exp);
        CHECK(areEqual(d, Value{0.}));
    }
}
