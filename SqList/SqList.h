//Data Structure (mainly C++)
//2.1 Sequence List (based on Array)
//
//Attention: You need to include both header file and cpp file
//           as template classes are defined and implemented in different files!
//
// Created by Landy on 2018/4/10.
//

#pragma once
#ifndef SQLIST_H
#define SQLIST_H

#include "../Header/Status.h"
const unsigned LIST_INIT_SIZE = 100;
const unsigned LIST_INCREMENT = 10;

template<typename T>
class SqList {
private:
    T *elem;    //存储空间基址
    int length;    //当前长度
    int listsize;    //当前分配的存储容量
public:
    SqList();
    ~SqList();
    void resize(int size);
    void listInsert(int i, T e);
    T listDelete(int i);
    int size() { return length; }
    bool isEmpty() { return length == 0; }
    void display();
};

#endif //SQLIST_H
