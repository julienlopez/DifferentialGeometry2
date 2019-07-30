#pragma once

#include <boost/variant.hpp>

struct Constant
{

};

struct Sum;

using Expression = boost::variant<Constant, Sum>;