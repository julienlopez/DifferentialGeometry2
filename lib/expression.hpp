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
struct Product;
struct Cos;
struct Sin;

using Expression
    = boost::variant<Constant, Value, Variable, boost::recursive_wrapper<Sum>, boost::recursive_wrapper<Product>,
                     boost::recursive_wrapper<Cos>, boost::recursive_wrapper<Sin>>;

struct Sum
{
    Expression left;
    Expression right;
};

bool operator==(const Sum& s1, const Sum& s2);

struct Product
{
    Expression left;
    Expression right;
};

bool operator==(const Product& s1, const Product& s2);

struct Cos
{
    Expression expr;
};

bool operator==(const Cos& c1, const Cos& c2);

struct Sin
{
    Expression expr;
};

bool operator==(const Sin& s1, const Sin& s2);