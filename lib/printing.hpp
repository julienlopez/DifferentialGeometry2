#pragma once

#include "expression.hpp"

#include <iosfwd>
#include <string>

std::wstring to_string(const Expression& exp);

std::wostream& operator<<(std::wostream& o, const Expression& exp);
