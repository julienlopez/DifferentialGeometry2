#include "printing.hpp"

namespace
{

struct Printer : public boost::static_visitor<std::wstring>
{

    std::wstring operator()(const Constant c) const
    {
        return c.name;
    }

    std::wstring operator()(const Value v) const
    {
        return std::to_wstring(v.value);
    }

    std::wstring operator()(const Variable v) const
    {
        return v.name;
    }

    std::wstring operator()(const Sum& s) const
    {
        return L"";
    }

    std::wstring operator()(const Product& p) const
    {
        return L"";
    }

    std::wstring operator()(const Cos& c) const
    {
        return L"cos(" + boost::apply_visitor(*this, c.expr) + L")";
    }

    std::wstring operator()(const Sin& s) const
    {
        return L"sin(" + boost::apply_visitor(*this, s.expr) + L")";
    }
};
}

std::wstring to_string(const Expression& exp)
{
    return boost::apply_visitor(Printer{}, exp);
}

std::wostream& operator<<(std::wostream& o, const Expression& exp)
{
    return o << to_string(exp);
}
