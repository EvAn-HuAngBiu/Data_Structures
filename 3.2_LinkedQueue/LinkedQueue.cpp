//
// Created by Evan on 2018/5/3.
//

#include "LinkedQueue.h"

template<typename T>
LinkedQueue<T>::LinkedQueue() {
    front = rear = new QNode();
    front->next = nullptr;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    while (front) {
        rear = front->next;
        delete front;
        front = rear;
    }
}

template<typename T>
bool LinkedQueue<T>::isEmpty() {
    return (front == rear);
}

template<typename T>
void LinkedQueue<T>::enqueue(T elem) {
    QNode *node = new QNode();
    node->data = elem;
    node->next = nullptr;
    rear->next = node;
    rear = node;
}

template<typename T>
T LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw "Empty queue";
    }
    QNode *p = front->next;
    front->next = p->next;
    T val = p->data;
    if (rear == p) {
        // 当只有一个元素且被删除时, 头尾指向一点
        rear = front;
    }
    delete p;
    return val;
}

template<typename T>
void LinkedQueue<T>::clear() {
    if (front == rear) {
        // 空队列
        return;
    }
    QNode *p = front->next;
    while (p) {
        QNode *q = p->next;
        delete p;
        p = q;
    }
    rear = front;
}

template<typename T>
int LinkedQueue<T>::length() {
    int len = 0;
    QNode *p = front;
    while (p->next) {
        p = p->next;
        len++;
    }
    return len;
}

template<typename T>
T LinkedQueue<T>::getHead() {
    if (isEmpty()) {
        throw "Empty queue";
    }
    return front->next->data;
}
