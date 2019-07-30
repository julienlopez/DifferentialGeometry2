#include "derivative.hpp"

Expression Derivative::operator()(const Constant cst) const
{
    return Value{0.};
}
