//
// Created by Landy on 2018/4/21.
//

#include <cstdlib>
#include <iostream>
#include "LinkedSqList.h"

template<typename T>
LinkedSqList<T>::LinkedSqList() {
    //构造一个空链表
    head = new LNode();
    head->next = NULL;
}

template<typename T>
LinkedSqList<T>::~LinkedSqList() {
    //销毁链表中所有结点
    LNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void LinkedSqList<T>::createList_H(int n, T *src) {
    //头插法建立链表
    //参数n指示插入元素个数, 数组src保存要插入的值
    if(n <= 0) {
        throw "Invalid argument of length";
    }
    for (int i = n - 1; i >= 0; i--)
    {
        LNode *temp = new LNode();
        temp->data = src[i];
        temp->next = head->next;
        head->next = temp;
    }
}

template<typename T>
void LinkedSqList<T>::createList_L(int n, T *src) {
    //尾插法建立链表
    //参数n指示插入元素个数, 数组src保存要插入的值
    if(n <= 0) {
        throw "Invalid argument of length";
    }
    LNode *prior = head;
    for (int i = 0; i < n; i++)
    {
        LNode *temp = new LNode();
        temp->data = src[i];
        temp->next = NULL;
        prior = prior->next = temp;
    }
}

template<typename T>
void LinkedSqList<T>::insertList(int i, T elem) {
    LNode *p = head;
    int j = 0;
    while(p && j < i - 1) {
        //遍历至第i-1个结点
        p = p->next;
        j++;
    }
    if(!p || j > i - 1) {
        //插入位置不合法
        //p为NULL时可能超长也可能为空表
        //j > i - 1 时指示插入位置为非正数
        throw "Invalid index";
    }
    LNode *newNode = new LNode();
    newNode->data = elem;
    newNode->next = p->next;
    p->next = newNode;
}

template<typename T>
T LinkedSqList<T>::deleteList(int i) {
    LNode *p = head;
    int j = 0;
    while(p->next && j < i - 1) {
        //遍历至第i-1个结点
        p = p->next;
        j++;
    }
    if(!p->next || j > i - 1) {
        //插入位置不合法
        //p为NULL时可能超长也可能为空表
        //j > i - 1 时指示插入位置为非正数
        throw "Invalid index";
    }
    LNode *deleted = p->next;
    p->next = deleted->next;
    T val = deleted->data;
    delete deleted;
    return val;
}

template<typename T>
bool LinkedSqList<T>::findList(T elem) {
    LNode *p = head->next;
    while(p && elem != p->data) {
        p = p->next;
    }
    return p != nullptr;
}

template<typename T>
void LinkedSqList<T>::display() {
    LNode *p = head->next;
    while(p) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

template<typename T>
void LinkedSqList<T>::split(LinkedSqList<T> &newList) {
    LNode *current = head->next, *tail_a = head, *tail_b = newList.head;
    int count = 1;
    while(current) {
        if(count % 2) {
            //奇数添加到heada即当前表中
            tail_a->next = current;
            tail_a = current;
        } else {
            tail_b->next = current;
            tail_b = current;
        }
        current = current->next;
        count++;
    }
    tail_a->next = tail_b->next = nullptr;
}