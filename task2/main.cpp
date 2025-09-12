#include "include/my_math.hpp"
#include "include/ans_handler.hpp"  // ← ДОБАВЬТЕ ЭТУ СТРОКУ!
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::cout << "Trigonometric Functions Calculator" << std::endl;
    std::cout << "==================================" << std::endl;
    
    // Test values
    double test_values[] = {0.0, M_PI/6, M_PI/4, M_PI/3, M_PI/2, M_PI};
    
    for (double x : test_values) {
        std::cout << "\nFor x = " << x << " radians:" << std::endl;
        std::cout << std::fixed << std::setprecision(6);
        
        try {
            AnswerHandler sin_result = my_sin(x);
            AnswerHandler cos_result = my_cos(x);
            AnswerHandler tan_result = my_tan(x);
            
            std::cout << "my_sin(" << x << ") = " << sin_result.result 
                     << " (std::sin = " << std::sin(x) << ")" << std::endl;
            std::cout << "my_cos(" << x << ") = " << cos_result.result 
                     << " (std::cos = " << std::cos(x) << ")" << std::endl;
            
            if (fabs(x - M_PI/2) > 1e-6 && fabs(x - 3*M_PI/2) > 1e-6) {
                std::cout << "my_tan(" << x << ") = " << tan_result.result 
                         << " (std::tan = " << std::tan(x) << ")" << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}