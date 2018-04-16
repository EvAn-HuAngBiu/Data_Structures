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
int SqList<T>::findList(T e) {
    //在线性表中查找元素e并返回其索引
    //如果查找元素不存在则返回-1
    for(int i = 0 ; i < length; i++) {
        if(elem[i] == e) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void SqList<T>::insertList(int i, T e) {
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
void SqList<T>::deleteList1(T e) {
    //删除顺序表中指定值e并返回
    //如果指定元素不存在则不操作
    int pos = this->findList(e);
    if(pos == -1) {
        //元素不存在，返回
        return;
    }
    for(int i = pos; i < length; i++) {
        elem[i] = elem[i + 1];
    }
    length--;
    if(length <= listsize / 4) {
        //分配的空间过多，归还部分空间
        resize(listsize / 2);
    }
}

template<typename T>
T SqList<T>::deleteList2(int i) {
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
    if(length <= listsize / 4) {
        //分配的空间过多，归还部分空间
        resize(listsize / 2);
    }
    return val;
}

template<typename T>
void SqList<T>::display() {
    for(int i = 0; i < length; i++) {
        std::cout << elem[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void SqList<T>::unionList(SqList<T> b) {
    int la_len = this->length + 1;    //在末尾插入即在length+1前插入元素
    for(int i = 1; i <= b.length; i++) {
        //如果在当前表中没找到元素则插入, 否则跳过
        //elem元素的数组下标比位序少1
        if(this->findList(b.elem[i - 1]) == -1) {
            this->insertList(la_len++, b.elem[i - 1]);
        }
    }
}

template<typename T>
void SqList<T>::deleteBetween(int x, int y) {
    //删除顺序表中值大于等于x且小于y的元素 [x,y)
    //这个操作只适用于泛型T指示为整形变量的实例
    if(x <= y) {
        //区间不合法
        throw "Interval is not valid";
    }
    int count = 0;    //记录有效元素个数
    for(int i = 0; i < length; i++) {
        if(elem[i] >= x && elem[i] < y) {
            continue;
        } else {
            elem[count++] = elem[i];
        }
    }
    length = count;
}





