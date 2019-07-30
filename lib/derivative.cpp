#include "derivative.hpp"

Expression Derivative::operator()(const Constant) const
{
    return Value{0.};
}

Expression Derivative::operator()(const Value) const
{
    return Value{0.};
}

Expression Derivative::operator()(const Variable var) const
{
    return Value{m_variable_name == var.name ? 1. : 0.};
}
