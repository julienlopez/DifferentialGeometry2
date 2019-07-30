#include "expression.hpp"

#include "comparison.hpp"

bool operator==(const Constant& c1, const Constant& c2)
{
    return c1.name == c2.name;
}

bool operator==(const Value& v1, const Value& v2)
{
    return v1.value == v2.value;
}

bool operator==(const Variable& v1, const Variable& v2)
{
    return v1.name == v2.name;
}

bool operator==(const Sum& s1, const Sum& s2)
{
    return areEqual(s1.left, s2.left) && areEqual(s1.right, s2.right);
}
