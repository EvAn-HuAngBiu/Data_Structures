#pragma once
//
// Created by Evan on 2018/5/2.
//

#ifndef INC_3_1_ARRAYSTACK_EVALUATEEXPRESSION_H
#define INC_3_1_ARRAYSTACK_EVALUATEEXPRESSION_H

#include <string>

class Evaluate {
private:
    std::string exp;    // 源表达式
    std::string postfix;    // 后缀表达式
public:
    explicit Evaluate(const std::string &exp) : exp(exp) {}

    std::string getResult() const { return postfix; }

    void convert();

    bool isOperator(char) const;

    int operatorPrior(char, char) const;

    //double caculate();
};

#endif //INC_3_1_ARRAYSTACK_EVALUATEEXPRESSION_H
