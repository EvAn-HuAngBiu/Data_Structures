#include "stdafx.h"
#include "SingleLinkedList.h"

template<typename T>
SingleLinkList<T>::SingleLinkList()
{
    head = new Node<T>();
    head->next = NULL;
    length = 0;
}

template<typename T>
SingleLinkList<T>::~SingleLinkList()
{
    LinkList temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
Status SingleLinkList<T>::CreateList_S(int n, T src[])
{
    //˳���ʼ��һ������Ϊn������
    //����srcΪÿ��Ҫ��ʼ��������Ԫ������
    //�����鳤��С��n, �����ִ���
    //�����鳤�ȴ���n, ��������ݽ����ض�
    LinkList prior = head;
    for (int i = 0; i < n; i++)
    {
        LinkList temp = new Node<T>();
        temp->elem = src[i];
        temp->next = NULL;
        prior = prior->next = temp;
    }
    length = n;
    return OK;
}

template<typename T>
Status SingleLinkList<T>::CreateList_IS(int n, T src[])
{
    //��λ���ʼ��һ������Ϊn������
    //����srcΪÿ��Ҫ��ʼ��������Ԫ������
    //�����鳤��С��n, �����ִ���
    //�����鳤�ȴ���n, ��������ݽ����ض�
    for (int i = n - 1; i >= 0; i--)
    {
        LinkList temp = new Node<T>();
        temp->elem = src[i];
        temp->next = head->next;
        head->next = temp;
    }
    length = n;
    return OK;
}

template<typename T>
Status SingleLinkList<T>::ClearList()
{
    //��������������ͷ���
    LinkList temp = head->next;
    while (temp)
    {
        head->next = temp->next;
        delete temp;
        temp = head->next;
    }
    length = 0;
    return OK;
}

template<typename T>
Status SingleLinkList<T>::EmptyList()
{
    return length == 0;
}

template<typename T>
int SingleLinkList<T>::ListLength()
{
    return length;
}

template<typename T>
T SingleLinkList<T>::GetElem(int i)
{
    if (i < 1 || i > length) return NULL;
    LinkList p = head->next;
    int current = 1;
    while (current++ < i)
        p = p->next;
    return p->elem;
}

template<typename T>
int SingleLinkList<T>::LocateElem(T src, bool(*compare)(T src, T cmp))
{
    LinkList p = head->next;
    int current = 1;
    while (p)
    {
        if (compare(p->elem, src))
            return current;
        current++;
        p = p->next;
    }
    return FALSE;
}

template<typename T>
T SingleLinkList<T>::PriorElem(T src)
{
    //����ǰ��Ԫ�أ������ͷ��㣬��Ϊ�䲻�洢��������
    if (src == head->next->elem) return FALSE;  //��Ԫ��û��ǰ��
    LinkList p = head->next;
    while (p->next)
    {
        if (p->next->elem == src)
            return p->elem;
        p = p->next;
    }
    return ERROR;
}

template<typename T>
T SingleLinkList<T>::NextElem(T src)
{
    LinkList p = head->next;
    while (p && p->next)
    {
        if (p->elem == src) return p->next->elem;
        else p = p->next;
    }
    return FALSE;
}

template<typename T>
Status SingleLinkList<T>::Append(T l)
{
    int current = 1;
    LinkList p = head->next;
    while (current++ < length)
        p = p->next;
    LinkList temp = new Node<T>();
    if (!temp) return FALSE;    //�ռ����ʧ��
    temp->elem = l;
    temp->next = NULL;
    p->next = temp;
    length++;
    return OK;
}

template<typename T>
T SingleLinkList<T>::Remove()
{
    int current = 1;
    LinkList p = head->next;
    while (current++ < length - 1)
        p = p->next;
    T val = p->next->elem;
    delete p->next;
    p->next = NULL;
    length--;
    return val;
}

template<typename T>
Status SingleLinkList<T>::Insert(int i, T l)
{
    if (i < 1 || i > length) return ERROR;
    int current = 1;
    LinkList p = head->next;
    while (current++ < i - 1)
        p = p->next;
    LinkList temp = new Node<T>();
    if (!temp) return FALSE;    //�ռ����ʧ��
    temp->elem = l;
    temp->next = p->next;
    p->next = temp;
    length++;
    return OK;
}

template<typename T>
T SingleLinkList<T>::Delete(int i)
{
    if (i < 1 || i > length) return ERROR;
    int current = 1;
    LinkList p = head->next;
    while (current++ < i - 1)
        p = p->next;
    LinkList temp = p->next;
    T val = temp->elem;
    p->next = temp->next;
    delete temp;
    length--;
    return val;
}

template<typename T>
void SingleLinkList<T>::Display()
{
    LinkList p = head->next;
    while (p)
    {
        std::cout << p->elem << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
