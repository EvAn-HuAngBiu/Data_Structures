//
// Created by Landy on 2018/4/10.
//

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "SqList.h"

template<typename T>
SqList<T>::SqList() {
    //C: elem = (T *)malloc(LIST_INIT_SIZE * sizeof(T));
    elem = new T[LIST_INIT_SIZE];
    if (!elem) throw "Allocate failed";    //存储空间分配失败
    length = 0;
    listsize = LIST_INIT_SIZE;
}

template<typename T>
SqList<T>::~SqList() {
    delete[] elem;
    //C: free(elem)
}

template<typename T>
void SqList<T>::resize(int size) {
    //C++ 不支持realloc的重新分配空间
    //C: auto newbase = (T *)realloc(elem, size);
    auto newbase = new T[size];
    //拷贝原数组内容到新数组中
    memcpy(newbase, elem, size * sizeof(T));
    delete[] elem;
    elem = newbase;
    listsize = size;
}

template<typename T>
void SqList<T>::listInsert(int i, T e) {
    //在顺序表中第i个位置之前插入元素e
    if (i < 1 || i > length + 1) {
        //索引不合法
        throw "Index is out of boundary";
    }
    if (length >= listsize) {
        //空间不足
        resize(listsize + LIST_INCREMENT);
    }
    //q为插入位置
    T *q = &elem[i - 1];
    for (T *p = &elem[length - 1]; p >= q; --p) {
        *(p + 1) = *p;
    }
    /* 另一种逻辑，利用数组下标:
     *
     * for (int i = length - 1; i >= index - 1; i--)
     *     elem[i + 1] = elem[i];
     * */
    *q = e;
    ++length;
}

template<typename T>
T SqList<T>::listDelete(int i) {
    //在顺序表中删除第i个元素并返回其值
    if(i < 1 || i > length) {
        //索引不合法
        throw "Index is out of boundary";
    }
    //p为删除位置
    T *p = &elem[i - 1];
    //val保存被删除的值
    T val = *p;
    for(++p; p <= &elem[length - 1]; ++p) {
        *(p - 1) = *p;
    }
    /* 同理:
     *
     * for(int j = i; j < length; j++)
     *     elem[j - 1] = elem[j];
     * 或
     * for (int i = i - 1; i < length; i++)
     *     elem[i] = elem[i + 1];
     * */
    --length;
    return val;
}

template<typename T>
void SqList<T>::display() {
    for(int i = 0; i < length; i++) {
        std::cout << elem[i] << " ";
    }
    std::cout << std::endl;
}

