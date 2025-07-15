#include "Solver.h"
#include <math.h>
#include <stdexcept>

std::vector<double> Solve(double a, double b, double c) {

    if (std::isnan(a) || std::isnan(b) || std::isnan(c) ||
        std::isinf(a) || std::isinf(b) || std::isinf(c)) {
        throw std::invalid_argument("Coefficients cannot be NaN or Infinity");
    }

    if (std::abs(a) < std::numeric_limits<double>::epsilon())
        throw std::invalid_argument("Coefficient a cannot be 0");

    std::vector<double> result;

    double D = b * b - 4 * a * c;

    if (D > 0) {
        result.emplace_back((-b + std::sqrt(D)) / (2 * a));
        result.emplace_back((-b - std::sqrt(D)) / (2 * a));
    } else if (std::abs(D) < std::numeric_limits<double>::epsilon()) {
        result.emplace_back(-b / (2 * a));
    }

    return result;
}