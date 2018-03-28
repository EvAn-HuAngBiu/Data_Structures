#pragma once
#ifndef _SQ_STACK_H
#define _SQ_STACK_H

const int STACK_INIT_SIZE = 5;
const int STACKINCREMENT = 5;

template<typename  T>
class SqStack
{
private:
    T * base;   //ջ����
    T * top;    //ջ��ָ��
    int stacksize;  //��ǰ�ѷ���Ĵ洢�ռ�
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
    if (!base) exit(-1);    //�洢�ռ����ʧ��
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
    int current_item = top - base;  //��ǰջ��Ԫ������
    T *temp = new T[size];
    if (!temp) return false;
    memcpy_s(temp, size * sizeof(T), 
        base, current_item * sizeof(T));    //����ԭ����������
    delete[] base;
    base = temp;
    top = base + current_item;
    stacksize = size;
    return true;
}

template<typename T>
inline bool SqStack<T>::clear()
{
    delete[] base;  //���ԭ������
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

