#pragma once

#include "expression.hpp"

#include <stdexcept>
#include <string>

struct Derivative : public boost::static_visitor<Expression>
{
    Derivative(std::wstring variable_name)
        : m_variable_name(std::move(variable_name))
    {
    }

    template <class T> Expression operator()(const T& t) const
    {
        throw std::runtime_error("not implemented yet");
        return {};
    }

    Expression operator()(const Constant) const;

    Expression operator()(const Value) const;

    std::wstring m_variable_name;
};
