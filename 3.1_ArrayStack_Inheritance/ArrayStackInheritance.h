//
// Created by Landy on 2018/4/24.
//

#ifndef INC_3_1_ARRAYSTACK_INHERITANCE_H
#define INC_3_1_ARRAYSTACK_INHERITANCE_H

#include "SqList.cpp"

template<typename T>
class ArrayStack : public SqList<T> {
private:
    //T &(*base) = elem;    // 数据基址

    // 在栈空间基址重分配时并没有修正栈顶的位置
    //T *top;    // 栈顶指针

    // 屏蔽栈中不支持的顺序表操作
    void insertList(int i, T e) override { ; }

    void deleteElem(T e) override { ; }

    T deleteIndex(int i) override { ; }

public:
    ArrayStack();

    virtual ~ArrayStack();

    // 把栈置为空栈
    void clearStack();

    // 若栈不空, 则返回栈顶元素, 否则返回NULL
    T getTop();

    // 入栈, 在顺序表尾插入元素
    void push(T e);

    // 若栈不空, 则将表尾元素出栈并返回, 否则返回NULL
    T pop();

};

#endif //INC_3_1_ARRAYSTACK_INHERITANCE_H
