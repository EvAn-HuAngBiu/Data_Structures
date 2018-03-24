#include "stdafx.h"
#include "SequenceList.h"


template<typename T>
SequenceList<T>::SequenceList()
{
    //���캯��, ����һ������Ϊ�յ����Ա�
    elem = new T[LIST_INIT_SIZE];    //�����ڴ�ռ�, ��ʼ��СΪ10
    if (!elem) exit(OVERFLOW);
    length = 0;
    listsize = LIST_INIT_SIZE;
}

template<typename T>
SequenceList<T>::~SequenceList()
{
    //��������
    delete[] elem;
    elem = NULL;     //�ͷ��ڴ���ÿ�ָ��
    if (elem) exit(ERROR);
    length = 0;
    listsize = 0;
}

template<typename T>
void SequenceList<T>::ClearList()
{
    //�����Ա�����Ϊ�ձ�
    length = 0;  //���ó���, ����ָ����������ͷ����, ����ԭ�б���Ԫ��
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
    //�ж����������Ƿ�Ϸ�
    if (index < 1 || index > length)
        throw "Index is illegeal";  //�׳��쳣ָʾ����Խ��
    return elem[index - 1];
}

template<typename T>
int SequenceList<T>::LocateElem(T e, bool(*compare)(T src, T cmp))
{
    int current = 0;    //ָʾ��ǰ��, ������������ʽ����0��ʼ��
    while (current <= length)
    {
        if(compare(elem[current++], e))
            return current; //����ֵ, ��ʵ��λ��ʽ����1��ʼ��
        continue;
    }
    return 0;
}

template<typename T>
T SequenceList<T>::PriorElem(T src)
{
    if (length <= 1 || elem[0] == src)
        return NULL;    //���Ԫ�ظ���С�ڵ���1��Ŀ��Ԫ��Ϊ��Ԫ��, ��û��ǰ��Ԫ��
    int current = 1;
    while (current < length)
    {
        if (src == elem[current++])
            return elem[current - 2];    //ǰ��Ԫ�غ�����˫�����õ��¼�2
        continue;
    }
    return NULL;    //Ԫ�ز�����
}

template<typename T>
T SequenceList<T>::NextElem(T src)
{
    if (length <= 1 || elem[length - 1] == src)
        return NULL;    //���Ԫ�ظ���С�ڵ���1��Ŀ��Ԫ��ΪβԪ��, ��û�к��Ԫ��
    int current = 0;
    while (current < length)
    {
        if(src == elem[current++])
            return elem[current];    //ǰ��Ԫ�غ�����˫�����õ��¼�2
        continue;
    }
    return NULL;    //Ԫ�ز�����
}

template<typename T>
void SequenceList<T>::ListInsert(int index, T e)
{
    //�����Ա��в���Ԫ��
    if (index < 1 || index > length + 1)
        throw "Index is illegeal";
    if (length + 1 > listsize)
    {
        //��������
        T *newbase = new T[listsize + LISTINCREMENT];
        if (!newbase) throw "Storage allocation failure";
        listsize += LISTINCREMENT;
        memcpy_s(newbase, listsize * sizeof(T), elem, length * sizeof(T));
        delete[] elem;
        elem = newbase;     //�µĻ�ַ
    }
    for (int i = length - 1; i >= index - 1; i--)   //Ӧ��βԪ�ؿ�ʼ���Ǩ��, ����Ḳ��
        elem[i + 1] = elem[i];
    elem[index - 1] = e;
    length++;
}

template<typename T>
T SequenceList<T>::ListDelete(int index)
{
    //�����Ա���ɾ��Ԫ��
    if (index < 1 || index > length)
    {
        cerr << "Index is illegeal" << endl;
        abort();
    }
    T popElement = elem[index - 1];
    for (int i = index - 1; i < length; i++)    //Ӧ��βԪ�ؿ�ʼ���Ǩ��, ����Ḳ��
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
