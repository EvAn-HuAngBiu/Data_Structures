#pragma once
//
// Created by Evan on 2018/5/3.
//

#ifndef INC_3_2_LINKEDQUEUE_H
#define INC_3_2_LINKEDQUEUE_H

template<typename T>
class LinkedQueue {
public:
    struct QNode {
        T data;
        QNode *next;
    };

    LinkedQueue();

    virtual ~LinkedQueue();

    bool isEmpty();

    void enqueue(T elem);

    T dequeue();

    void clear();

    int length();

    T getHead();

private:
    QNode *front;
    QNode *rear;
};



#endif //INC_3_2_LINKEDQUEUE_H
