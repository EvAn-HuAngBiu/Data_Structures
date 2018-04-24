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

const int LIST_INIT_SIZE = 100;
const int LIST_INCREMENT = 10;

template<typename T>
class SqList {
protected:
    T *elem;    //存储空间基址
    int length;    //当前长度
    int listsize;    //当前分配的存储容量
public:
    SqList();

    virtual ~SqList();

    void resize(int size);

    int findList(T e);

    virtual void insertList(int i, T e);

    virtual void deleteElem(T e);

    virtual T deleteIndex(int i);

    int size() { return length; }

    bool isEmpty() { return length == 0; }

    void unionList(SqList<T> s);

    void deleteBetween(int x, int y);

    template<typename Type>
    friend std::ostream &operator<<(std::ostream &, const SqList<Type> &);
};

#endif //SQLIST_H
