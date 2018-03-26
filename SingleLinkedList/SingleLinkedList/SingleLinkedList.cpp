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
    //顺序初始化一个长度为n的链表
    //数组src为每次要初始化的链表元素数据
    //若数组长度小于n, 将出现错误
    //若数组长度大于n, 多余的数据将被截断
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
    //逆位序初始化一个长度为n的链表
    //数组src为每次要初始化的链表元素数据
    //若数组长度小于n, 将出现错误
    //若数组长度大于n, 多余的数据将被截断
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
    //这个方法不会清除头结点
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
    //返回前驱元素，会忽略头结点，因为其不存储可用数据
    if (src == head->next->elem) return FALSE;  //首元素没有前驱
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
    if (!temp) return FALSE;    //空间分配失败
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
    if (!temp) return FALSE;    //空间分配失败
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
