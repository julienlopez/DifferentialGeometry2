#pragma once

#include "expression.hpp"

#include <stdexcept>

struct Derivative : public boost::static_visitor<Expression>
{

    template <class T> Expression operator()(const T& t) const
    {
        throw std::runtime_error("not implemented yet");
        return {};
    }

    Expression operator()(const Constant cst) const;
};
