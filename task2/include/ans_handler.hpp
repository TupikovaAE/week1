#ifndef ANS_HANDLER_HPP
#define ANS_HANDLER_HPP

struct AnswerHandler {
    double x;
    double result;
    
    // Constructor
    AnswerHandler(double x_val = 0.0, double res_val = 0.0) : x(x_val), result(res_val) {}
};

#endif // ANS_HANDLER_HPP