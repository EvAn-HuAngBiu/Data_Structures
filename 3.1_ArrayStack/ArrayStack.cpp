//
// Created by Landy on 2018/4/24.
//

#include <cstring>
#include "ArrayStack.h"

template<typename T>
ArrayStack<T>::ArrayStack() {
    base = new T[STACK_INIT_SIZE];
    top = base;    // 空栈, 栈顶和栈底指向同一块内存
    stacksize = STACK_INIT_SIZE;
}

template<typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] base;
    delete top;
}

template<typename T>
void ArrayStack<T>::clearStack() {
    // 空表, 只需要栈顶指向栈底即可
    top = base;
}

template<typename T>
bool ArrayStack<T>::isEmpty() {
    // 当栈顶和栈底一致时, 为空
    return top == base;
}

template<typename T>
int ArrayStack<T>::size() {
    // 栈顶和栈底的差值即长度
    return static_cast<int>(top - base);
}

template<typename T>
T ArrayStack<T>::getTop() {
    // top指针指向栈顶元素的下一个位置上, top - 1即栈顶
    return (top == base ? NULL : *(top - 1));
}

template<typename T>
void ArrayStack<T>::resize(int s) {
    int len = static_cast<int>(top - base);
    auto newBase = new T[s];
    memcpy(newBase, base, sizeof(T) * stacksize);
    delete[] base;
    base = newBase;
    top = base + len;
    stacksize = s;
}

template<typename T>
void ArrayStack<T>::push(T e) {
    if (this->size() >= stacksize) {
        //栈空间不足, 重新分配
        resize(stacksize + STACK_INCREMENT);
    }
    *top++ = e;
}

template<typename T>
T ArrayStack<T>::pop() {
    return (top == base ? NULL : *--top);
}

template<typename Type>
std::ostream &operator<<(std::ostream &os, const ArrayStack<Type> &s) {
    auto p = s.base;
    while (p != s.top) {
        os << *p++ << " ";
    }
    return os;
}
