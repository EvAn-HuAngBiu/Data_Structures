//
// Created by Landy on 2018/4/24.
//

#pragma once
#ifndef INC_3_1_ARRAYSTACK_H
#define INC_3_1_ARRAYSTACK_H

#include <iostream>

const int STACK_INIT_SIZE = 100;
const int STACK_INCREMENT = 10;

template<typename T>
class ArrayStack {
private:
    T *base;
    T *top;
    int stacksize;
public:
    ArrayStack();

    virtual ~ArrayStack();

    void clearStack();

    bool isEmpty();

    int size();

    T getTop();

    void resize(int s);

    void push(T e);

    T pop();

    template<typename Type>
    friend std::ostream &operator<<(std::ostream &, const ArrayStack<Type> &);
};


#endif //INC_3_1_ARRAYSTACK_H
