#include <iostream>
#include <cmath>
#include <cctype>
#include "ArrayStack.cpp"
#include "EvaluateExpression.h"

using namespace std;

string conversion(int num, int n);
bool bracketMatching(string arg);

int main1() {
    ArrayStack<int> stack;
    cout.setf(ios_base::boolalpha);
    cout << stack.size() << " " << stack.isEmpty() << endl;
    for (int i = 1; i <= 5; i++) {
        stack.push(i);
    }
    cout << stack << endl;
    stack.push(10);
    cout << stack << " Size: " << stack.size() << endl;

    /* cout自右向左结合
     * 如果 cout << stack.pop() << stack.size()
     * 会先计算右侧的stack.size()再pop, 导致结果出错
     * */
    cout << stack.pop() << endl;
    cout << "Size :" << stack.size() << endl;

    cout << conversion(1348, 8) << endl;
    cout << bracketMatching("([]{})([{}])") << endl;

}

int main() {
    Evaluate e("25*32/(29-12)+36*(42-18)");
    e.convert();
    cout << e.getResult() << endl;
}

string conversion(int num, int n) {
    // 将十进制数num转换为n进制数
    ArrayStack<int> stack;
    while (num) {
        stack.push(num % n);
        num /= n;
    }
    string result;
    while (!stack.isEmpty()) {
        result += std::to_string(stack.pop());
    }
    return result;
}

bool bracketMatching(string arg) {
    // 栈的应用：括号匹配
    ArrayStack<char> stack;
    const string left = "{[(";
    for (auto i : arg) {
        if (left.find(i) != string::npos) {
            stack.push(i);
        } else {
            if (stack.isEmpty()) {
                // 空栈不可能存在和右括号匹配的项, 失败
                return false;
            }
            switch (i) {
                case '}':
                    if (stack.pop() != '{') return false;
                    break;
                case ']':
                    if (stack.pop() != '[') return false;
                    break;
                case ')':
                    if (stack.pop() != '(') return false;
                    break;
                default:
                    return false;
            }
        }
    }
    return true;
}