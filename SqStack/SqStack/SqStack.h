#pragma once
#ifndef _SQ_STACK_H
#define _SQ_STACK_H

const int STACK_INIT_SIZE = 5;
const int STACKINCREMENT = 5;

template<typename  T>
class SqStack
{
private:
    T * base;   //栈数组
    T * top;    //栈顶指针
    int stacksize;  //当前已分配的存储空间
public:
    SqStack();
    virtual ~SqStack();
    bool resize(int size);
    bool clear();
    bool isEmpty() { return top == base; }
    int length() { return top - base; }
    T getTop() { return (base == top ? NULL : *(top - 1)); }
    void push(T e);
    T pop();
    void traverse(void(*visit)(T e));
};

#endif

template<typename T>
inline SqStack<T>::SqStack()
{
    base = new T[STACK_INIT_SIZE];
    if (!base) exit(-1);    //存储空间分配失败
    top = base;
    stacksize = STACK_INIT_SIZE;
}

template<typename T>
inline SqStack<T>::~SqStack()
{
    delete[] base;
}

template<typename T>
inline bool SqStack<T>::resize(int size)
{
    int current_item = top - base;  //当前栈内元素数量
    T *temp = new T[size];
    if (!temp) return false;
    memcpy_s(temp, size * sizeof(T), 
        base, current_item * sizeof(T));    //拷贝原有数组内容
    delete[] base;
    base = temp;
    top = base + current_item;
    stacksize = size;
    return true;
}

template<typename T>
inline bool SqStack<T>::clear()
{
    delete[] base;  //清空原有数组
    base = new T[STACK_INIT_SIZE];
    if (!base) return false;
    top = base;
    stacksize = STACK_INIT_SIZE;
    return true;
}

template<typename T>
inline void SqStack<T>::push(T e)
{
    if (top - base >= stacksize) resize(stacksize + STACKINCREMENT);
    *top++ = e;
}

template<typename T>
inline T SqStack<T>::pop()
{
    if (top - base <= 0) return NULL;
    return *--top;
}

template<typename T>
inline void SqStack<T>::traverse(void(*visit)(T e))
{
    T *temp = base;
    while (temp != top)
        visit(*temp++);
}

