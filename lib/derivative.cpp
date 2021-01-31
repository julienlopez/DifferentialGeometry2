#include "derivative.hpp"

#include "comparison.hpp"

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
    auto filter_lmbd = [](const Expression& e) { return areEqual(e, Value{0.}); };
    s.operands.erase(std::remove_if(begin(s.operands), end(s.operands), filter_lmbd), end(s.operands));
    if(s.operands.empty()) return Value{0.};
    if(s.operands.size() == 1) return s.operands.front();
    return s;
}
