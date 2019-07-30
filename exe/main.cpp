#include "expression.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Expression e;

    // HyperSurface<2, 3> torus({{(R+r.cos(u))cos(v)}, {(R+r.cos(u))sin(v)}, {r.sin(u)}});
    //{
    //    { Product{, Cos{Variable{L"u"}} },
    //    { Product{, Sin{Variable{L"u"}} },
    //    { Product{Constant{L"r"}, Sin{Variable{L"u"}} }
    //}
    // const auto metric_tensor = torus.metricTensor();
    // const auto riemann_tensor = torus.riemannTensor();
    // const auto ricci_tensor = torus.ricciTensor();
    // const auto scalar_curvature = torus.scalarCurvature();

    return 0;
}
