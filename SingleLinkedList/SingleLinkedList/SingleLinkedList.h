#pragma once
#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include "../../Header/Status.h";
#include <iostream>

//��㶨�� ��ģ��
template<typename T>
struct Node 
{
    T elem;
    Node<T> *next;
};

//��ͷ�������� ��ģ��
template<typename T>
class SingleLinkList
{
    typedef Node<T>* LinkList;
private:
    LinkList head;  //ͷԪ��, ���Ԫ�ص�����ֵ��Ч
    int length; //������
public:
    SingleLinkList();   //��ʼ��һ���յ�����
    ~SingleLinkList();  //����һ������
    Status CreateList_S(int n, T src[]);   //˳���ʼ��һ������Ϊn������
    Status CreateList_IS(int n, T src[]);  //��λ���ʼ��һ������Ϊn������
    Status ClearList(); //�����������Ԫ��
    Status EmptyList(); //ָʾ�����Ƿ�Ϊ��
    int ListLength();   //����������

    //��ȡ����Ԫ��
    T GetElem(int i);   //���������еĵ�iλ��Ԫ��
    int LocateElem(T src, bool(*compare)(T src, T cmp));   //������������src�����ϵcompare����������
    T PriorElem(T src); //����srcԪ�ص�ǰ��
    T NextElem(T src);  //����srcԪ�صĺ��

    //����ɾ������
    Status Append(T l);  //׷��һ�����
    T Remove();  //ɾ��β���
    Status Insert(int i, T l); //������i������l
    T Delete(int i);    //ɾ������Ϊi��Ԫ��

    void Display(); //�������ȫ������
};


#endif

