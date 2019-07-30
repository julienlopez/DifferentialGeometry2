#pragma once

#include "expression.hpp"

struct Derivative : public boost::static_visitor<Expression>
{
    template <class T> Expression operator()(const T& t) const
    {
        throw std::exception("not implemented yet");
    }

    Expression operator()(const Constant cst) const;
};
