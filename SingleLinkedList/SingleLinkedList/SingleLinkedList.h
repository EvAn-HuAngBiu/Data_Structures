#pragma once
#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include "../../Header/Status.h";
#include <iostream>

//结点定义 带模板
template<typename T>
struct Node 
{
    T elem;
    Node<T> *next;
};

//带头单链表定义 带模板
template<typename T>
class SingleLinkList
{
    typedef Node<T>* LinkList;
private:
    LinkList head;  //头元素, 这个元素的数据值无效
    int length; //链表长度
public:
    SingleLinkList();   //初始化一个空的链表
    ~SingleLinkList();  //销毁一个链表
    Status CreateList_S(int n, T src[]);   //顺序初始化一个长度为n的链表
    Status CreateList_IS(int n, T src[]);  //逆位序初始化一个长度为n的链表
    Status ClearList(); //清除链表所有元素
    Status EmptyList(); //指示链表是否为空
    int ListLength();   //返回链表长度

    //获取链表元素
    T GetElem(int i);   //返回链表中的第i位的元素
    int LocateElem(T src, bool(*compare)(T src, T cmp));   //返回链表中与src满足关系compare的链表索引
    T PriorElem(T src); //返回src元素的前驱
    T NextElem(T src);  //返回src元素的后继

    //插入删除功能
    Status Append(T l);  //追加一个结点
    T Remove();  //删除尾结点
    Status Insert(int i, T l); //在索引i处插入l
    T Delete(int i);    //删除索引为i的元素

    void Display(); //输出链表全部内容
};


#endif

