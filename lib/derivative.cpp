#include "derivative.hpp"

#include <algorithm>
#include <functional>

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

Expression Derivative::operator()(Sum s) const
{
    auto lmbd = [this](const Expression& e) { return boost::apply_visitor(*this, e); };
    std::transform(begin(s.operands), end(s.operands), begin(s.operands), lmbd);
    return s;
}
