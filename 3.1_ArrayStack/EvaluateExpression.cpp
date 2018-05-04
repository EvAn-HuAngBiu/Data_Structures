//
// Created by Evan on 2018/5/2.
//

#include "EvaluateExpression.h"
#include "ArrayStack.cpp"
#include <cctype>

bool Evaluate::isOperator(char src) const {
    return (src == '+') || (src == '-') || (src == '*') || (src == '/')
           || (src == '(') || (src == ')');
}

int Evaluate::operatorPrior(char src, char tar) const {
    // 判断操作符src和tar的优先级, 如果src优先于tar则返回true, 否则false
    // src应当是待压栈的运算符, tar是栈顶运算符

    /* 将算符优先关系抽象为数组
     * 0代表压入算符要先将栈顶算符弹出并加入后缀表达式
     * 1代表压入算符将栈顶算符弹出并丢弃
     * 2代表将算符压入栈顶
     * 列代表src, 行代表tar, 其中)优先级最低不可能存入栈中
     *   +  -  *  /  (
     * + 0  0  0  0  2
     * - 0  0  0  0  2
     * * 2  2  0  0  2
     * / 2  2  0  0  2
     * ( 2  2  2  2  2
     * ) 0  0  0  0  1
     *
     * */
    if (tar == NULL) return 2;
    int relations[6][5]{{0, 0, 0, 0, 2},
                        {0, 0, 0, 0, 2},
                        {2, 2, 0, 0, 2},
                        {2, 2, 0, 0, 2},
                        {2, 2, 2, 2, 2},
                        {0, 0, 0, 0, 1}};
    std::string str = "+-*/()";
    int src_index = str.find(src), tar_index = str.find(tar);
    return relations[src_index][tar_index];
}

void Evaluate::convert() {
    std::string current;    // 保存多位数值
    ArrayStack<char> optr;    // 运算符栈
    auto i = exp.begin();
    while (i != exp.end()) {
        current = "";    // 循环每次开始时, 置空
        while (isdigit(*i)) {
            // 如果该位是数值则添加到current中
            current += *i++;
        }
        if (!current.empty()) {
            // 将数值送入最终表达式并结束此轮循环
            postfix += current + " ";
            continue;
        }
        // 如果为运算符的情况
        if (!isOperator(*i)) {
            // 不是数字也不是运算符, 非法
            throw std::logic_error("Illegal expression");
        } else {
            switch (operatorPrior(*i, optr.getTop())) {
                case 0: {
                    postfix += optr.pop();
                    postfix += ' ';
                    if (*i == ')') continue;
                    else optr.push(*i);
                    break;
                }
                case 1:
                    optr.pop();
                    break;
                default:
                    optr.push(*i);
                    break;
            }
            i++;
        }
    }
    while (!optr.isEmpty()) {
        postfix += optr.pop();
        postfix += ' ';
    }
}