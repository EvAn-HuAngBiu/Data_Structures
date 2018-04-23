#include "stdafx.h"
#include "SequenceList.h"


template<typename T>
SequenceList<T>::SequenceList()
{
    //构造函数, 生成一个内容为空的线性表
    elem = new T[LIST_INIT_SIZE];    //分配内存空间, 初始大小为10
    if (!elem) exit(OVERFLOW);
    length = 0;
    listsize = LIST_INIT_SIZE;
}

template<typename T>
SequenceList<T>::~SequenceList()
{
    //析构函数
    delete[] elem;
    elem = NULL;     //释放内存后置空指针
    if (elem) exit(ERROR);
    length = 0;
    listsize = 0;
}

template<typename T>
void SequenceList<T>::ClearList()
{
    //将线性表重置为空表
    length = 0;  //重置长度, 将首指针移向数组头即可, 保留原有表内元素
}

template<typename T>
Status SequenceList<T>::ListEmpty()
{
    return length == 0 ? TRUE : FALSE;
}

template<typename T>
int SequenceList<T>::ListLength()
{
    return length;
}

template<typename T>
T SequenceList<T>::GetElem(int index)
{
    //判断需求索引是否合法
    if (index < 1 || index > length)
        throw "Index is illegeal";  //抛出异常指示索引越界
    return elem[index - 1];
}

template<typename T>
int SequenceList<T>::LocateElem(T e, bool(*compare)(T src, T cmp))
{
    int current = 0;    //指示当前数, 以数组索引形式（从0开始）
    while (current <= length)
    {
        if(compare(elem[current++], e))
            return current; //返回值, 以实际位形式（从1开始）
        continue;
    }
    return 0;
}

template<typename T>
T SequenceList<T>::PriorElem(T src)
{
    if (length <= 1 || elem[0] == src)
        return NULL;    //如果元素个数小于等于1或目标元素为首元素, 则没有前驱元素
    int current = 1;
    while (current < length)
    {
        if (src == elem[current++])
            return elem[current - 2];    //前驱元素和自增双重作用导致减2
        continue;
    }
    return NULL;    //元素不存在
}

template<typename T>
T SequenceList<T>::NextElem(T src)
{
    if (length <= 1 || elem[length - 1] == src)
        return NULL;    //如果元素个数小于等于1或目标元素为尾元素, 则没有后继元素
    int current = 0;
    while (current < length)
    {
        if(src == elem[current++])
            return elem[current];    //前驱元素和自增双重作用导致减2
        continue;
    }
    return NULL;    //元素不存在
}

template<typename T>
void SequenceList<T>::ListInsert(int index, T e)
{
    //在线性表中插入元素
    if (index < 1 || index > length + 1)
        throw "Index is illegeal";
    if (length + 1 > listsize)
    {
        //容量不足
        T *newbase = new T[listsize + LISTINCREMENT];
        if (!newbase) throw "Storage allocation failure";
        listsize += LISTINCREMENT;
        memcpy_s(newbase, listsize * sizeof(T), elem, length * sizeof(T));
        delete[] elem;
        elem = newbase;     //新的基址
    }
    for (int i = length - 1; i >= index - 1; i--)   //应从尾元素开始向后迁移, 否则会覆盖
        elem[i + 1] = elem[i];
    elem[index - 1] = e;
    length++;
}

template<typename T>
T SequenceList<T>::ListDelete(int index)
{
    //从线性表中删除元素
    if (index < 1 || index > length)
    {
        cerr << "Index is illegeal" << endl;
        abort();
    }
    T popElement = elem[index - 1];
    for (int i = index - 1; i < length; i++)    //应从尾元素开始向后迁移, 否则会覆盖
        elem[i] = elem[i + 1];
    length--;
    return popElement;
}

template<typename T>
void SequenceList<T>::ListTraverse(void(*visit)(T e))
{
    for (T element : elem)
        visit(element);
}

template<typename T>
void SequenceList<T>::Union(SequenceList list)
{
    for (T element : list.elem)
        if (this->LocateElem(element, equal) == 0)
            this->ListInsert(this->length + 1, element);
}

template<typename T>
void SequenceList<T>::Display()
{
    for (int i = 0;i < length; i++)
        cout << elem[i] << endl;
}
