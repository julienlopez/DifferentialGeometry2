#include "derivative.hpp"

Expression Derivative::operator()(const Constant) const
{
    return Value{0.};
}
Expression Derivative::operator()(const Value) const
{
    return Value{0.};
}
