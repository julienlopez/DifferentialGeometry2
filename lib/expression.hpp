#pragma once

#include <boost/variant/recursive_variant.hpp>

struct Constant
{
    std::wstring name;
};

bool operator==(const Constant& c1, const Constant& c2);

struct Value
{
    double value;
};

bool operator==(const Value& v1, const Value& v2);

struct Variable
{
    std::wstring name;
};

bool operator==(const Variable& v1, const Variable& v2);

// struct Monomial
// {
//     double multiplier;
//     Variable variable;
//     int exponant = 1;
// };

struct Sum;

using Expression = boost::variant<Constant, Value, Variable, boost::recursive_wrapper<Sum>>;

struct Sum
{
    Expression left;
    Expression right;
};

bool operator==(const Sum& s1, const Sum& s2);
