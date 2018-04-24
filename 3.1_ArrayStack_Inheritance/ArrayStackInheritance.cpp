//
// Created by Landy on 2018/4/24.
//

#include "ArrayStackInheritance.h"

template<typename T>
ArrayStack<T>::ArrayStack() : SqList<T>() {
    //top = SqList<T>::elem;    // 空栈, top和base指向同一内存块
}

template<typename T>
ArrayStack<T>::~ArrayStack() {
    //delete top;
}

template<typename T>
void ArrayStack<T>::clearStack() {
    //不删除元素, 直接将长度置0即可
    SqList<T>::length = 0;
}

template<typename T>
T ArrayStack<T>::getTop() {
    T val = *(SqList<T>::elem + SqList<T>::length - 1);
    return (SqList<T>::length ? NULL : val);
}

template<typename T>
void ArrayStack<T>::push(T e) {
    //相当于在顺序表尾插入元素e
    SqList<T>::insertList(SqList<T>::length + 1, e);
}

template<typename T>
T ArrayStack<T>::pop() {
    //删除顺序表尾的元素并返回
    return SqList<T>::deleteIndex(SqList<T>::length);
}
