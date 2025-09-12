#include "../include/my_math.hpp"
#include <cmath>
#include <stdexcept>

// Helper function to calculate factorial
long long factorial(int n) {
    if (n < 0) throw std::invalid_argument("Factorial of negative number");
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Taylor series expansion for sin(x)
AnswerHandler my_sin(double x) {
    // Normalize x to range [-2π, 2π]
    x = fmod(x, 2 * M_PI);
    
    double result = 0.0;
    const int terms = 10;
    
    for (int n = 0; n < terms; ++n) {
        double term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
        result += term;
    }
    
    return AnswerHandler(x, result);
}

// Taylor series expansion for cos(x)
AnswerHandler my_cos(double x) {
    x = fmod(x, 2 * M_PI);
    
    double result = 0.0;
    const int terms = 10;
    
    for (int n = 0; n < terms; ++n) {
        double term = pow(-1, n) * pow(x, 2 * n) / factorial(2 * n);
        result += term;
    }
    
    return AnswerHandler(x, result);
}

// tan(x) = sin(x)/cos(x)
AnswerHandler my_tan(double x) {
    AnswerHandler sin_result = my_sin(x);
    AnswerHandler cos_result = my_cos(x);
    
    if (fabs(cos_result.result) < 1e-10) {
        throw std::domain_error("Tangent undefined for this angle");
    }
    
    return AnswerHandler(x, sin_result.result / cos_result.result);
}