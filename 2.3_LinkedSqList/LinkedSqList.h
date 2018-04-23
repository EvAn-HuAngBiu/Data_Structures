//
// Attention: This file should not be included!
//            You need to include LinkedSqList.cpp
//
// Created by Landy on 2018/4/20.
//

#pragma once
#ifndef LINKEDSQLIST_LINKEDSQLIST_H
#define LINKEDSQLIST_LINKEDSQLIST_H

template<typename T>
class LinkedSqList {
private:
    struct LNode {
        T data;
        LNode *next;
    };

    LNode *head;                           //头结点
public:
    LinkedSqList();                        //初始化一个空链表
    virtual ~LinkedSqList();              //销毁链表
    void createList_H(int n, T src[]);    //头插法创建链表
    void createList_L(int n, T src[]);    //尾插法创建链表
    void insertList(int i, T elem);       //在指定位置插入元素
    T deleteList(int i);                  //删除第i个元素
    bool findList(T elem);                //在列表中查找元素
    void display();                       //显示链表全部元素
    bool isEmpty()                        //返回是否为空链表
    { return head->next == nullptr; }

    void split(LinkedSqList<T> &newList);
};


#endif //LINKEDSQLIST_LINKEDSQLIST_H
