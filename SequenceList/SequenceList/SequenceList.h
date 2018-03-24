#pragma once
#ifndef SequenceList_H
#define SequenceList_H
#include "Status.h"
//预定义常量声明
const int LIST_INIT_SIZE = 10;
const int LISTINCREMENT = 100;


template<typename T>
class SequenceList
{
private:
        T *elem;
        int length;
        int listsize;
public:
    SequenceList();
    virtual ~SequenceList();
    void ClearList();
    Status ListEmpty();
    int ListLength();
    T GetElem(int index);
    int LocateElem(T e, bool(*compare)(T src, T cmp));
    T PriorElem(T src);
    T NextElem(T src);
    void ListInsert(int index, T e);
    T ListDelete(int index);
    void ListTraverse(void(*visit)(T e));
    void Union(SequenceList list);
    void Display();
};

#endif

