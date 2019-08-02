#include <catch2/catch.hpp>

#include "printing.hpp"

TEST_CASE("Expression Printing", "[expression]")
{

    SECTION("printing a constant")
    {
        const std::wstring name{L"x"};
        const auto str = to_string(Constant{name});
        CHECK(str == name);
    }

    SECTION("printing a value")
    {
        const double v = 1;
        const auto str = to_string(Value{v});
        CHECK(str == std::to_wstring(v));
    }

    SECTION("printing a variable")
    {
        const std::wstring name{L"x"};
        const auto str = to_string(Variable{name});
        CHECK(str == name);
    }

	SECTION("printing cos(x)")
	{
        CHECK(to_string(Cos{Variable{L"x"}}) == L"cos(x)");
	}

    SECTION("printing sin(x)")
    {
        CHECK(to_string(Sin{Variable{L"x"}}) == L"sin(x)");
    }
}
