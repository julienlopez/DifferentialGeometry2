#include "comparison.hpp"

struct Comparison : public boost::static_visitor<bool>
{
    template <class T> bool operator()(const T& exp1, const T& exp2) const
    {
        return exp1 == exp2;
    }

    template <class T, class U> bool operator()(const T& exp1, const U& exp2) const
    {
        return false;
    }
};

bool areEqual(const Expression& exp1, const Expression& exp2)
{
    return boost::apply_visitor(Comparison{}, exp1, exp2);
}
