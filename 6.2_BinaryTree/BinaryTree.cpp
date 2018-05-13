//
// Created by Evan on 2018/5/13.
//

#include <iostream>
#include "BinaryTree.h"
#include <stack>


void BinaryTree::preOrderCreate() {
    preOrderCreate(this->Tree);
}

void BinaryTree::preOrderCreate(BinaryTree::BiTNode *&cur) {
    // ���밴������˳������
    // ��������: -+a  *b  -c  d  /e  f  #
    // ������Ҷ�ڵ�ʱ����Ҫ�������ո��������ӽڵ�Ϊ��

    auto ch = static_cast<char>(std::cin.get());
    if (ch == ' ') {
        cur = nullptr;
    } else if (ch == '#') {
        return;
    } else {
        cur = new BiTNode();
        cur->data = ch;
        preOrderCreate(cur->lchild);
        preOrderCreate(cur->rchild);
    }
}

void BinaryTree::preOrderPrint() const {
    // ����ݹ������ǰ��������ֱ�ӵ��õݹ麯��
    preOrderPrint(this->Tree);
}

void BinaryTree::inOrderPrint() const {
    // ����ݹ������ǰ��������ֱ�ӵ��õݹ麯��
    inOrderPrint(this->Tree);
}

void BinaryTree::postOrderPrint() const {
    // ����ݹ������ǰ��������ֱ�ӵ��õݹ麯��
    postOrderPrint(this->Tree);
}

void BinaryTree::preOrderPrint(const BinaryTree::BiTNode *cur) const {
    // ��������ĵݹ麯��
    if (cur) {
        std::cout << cur->data;
        preOrderPrint(cur->lchild);
        preOrderPrint(cur->rchild);
    }
}

void BinaryTree::inOrderPrint(const BinaryTree::BiTNode *cur) const {
    // ��������ĵݹ麯��
    if (cur) {
        inOrderPrint(cur->lchild);
        std::cout << cur->data;
        inOrderPrint(cur->rchild);
    }
}

void BinaryTree::postOrderPrint(const BinaryTree::BiTNode *cur) const {
    // ��������ĵݹ麯��
    if (cur) {
        postOrderPrint(cur->lchild);
        postOrderPrint(cur->rchild);
        std::cout << cur->data;
    }
}

void BinaryTree::preOrderPrint_NonRecursive() const {
    if (!Tree) {
        // ����
        return;
    }
    // �ǵݹ�ʵ�ֶ�����ǰ�����(DLR)
    std::stack<BiTNode *> S;
    auto p = Tree;
    while (p || !S.empty()) {
        while (p) {
            std::cout << p->data;
            S.push(p);
            p = p->lchild;
        }
        if (!S.empty()) {
            p = S.top();
            S.pop();
            p = p->rchild;
        }
    }
}

void BinaryTree::inOrderPrint_NonRecursive1() const {
    // ����ǵݹ����(LDR)
    if (!Tree) {
        // ����
        return;
    }
    std::stack<BiTNode *> S;
    // �������ջ����
    S.push(Tree);
    while (!S.empty()) {
        auto p = S.top();
        while (p) {
            p = S.top()->lchild;
            S.push(p);
        }
        // �ս����ջ
        S.pop();
        if (!S.empty()) {
            std::cout << S.top()->data;
            p = S.top()->rchild;
            S.pop();
            S.push(p);
        }
    }
}

void BinaryTree::inOrderPrint_NonRecursive2() const {
    // ����ǵݹ����������2(LDR)
    std::stack<BiTNode *> S;
    auto p = Tree;
    while (p || !S.empty()) {
        while(p) {
            S.push(p);
            p = p->lchild;
        }
        if (!S.empty()) {
            p = S.top();
            S.pop();
            std::cout << p->data;
            p = p->rchild;
        }
    }
}

void BinaryTree::postOrderPrint_NonRecursive1() const {
    // ���ø���ָ��ĺ������, curָ��ǰ����Ľ�㣬preָ����һ������Ľ��
    // �����������1. ��ǰ���û�����Ӻ��Һ���
    //             2. ��ǰ���ĺ����Ѿ������ʹ�����pre��cur���ӽ��
    // ��ʱ��ջ������ջ�����
    // ���� Ӧ���Ƚ��Һ����ٽ�������ջ����

    BiTNode *cur, *pre = nullptr;
    std::stack<BiTNode *> S;
    // ���������ջ����
    S.push(Tree);
    while (!S.empty()) {
        cur = S.top();
        if ((!cur->lchild && !cur->rchild) ||
            (pre && (pre == cur->lchild || pre == cur->rchild))) {
            std::cout << cur->data;
            S.pop();
            pre = cur;
        } else {
            if (cur->rchild) {
                S.push(cur->rchild);
            }
            if (cur->lchild) {
                S.push(cur->lchild);
            }
        }
    }
}

void BinaryTree::postOrderPrint_NonRecursive2() const {
    // ���ø�������ջ��ָʾ��ǰջ������Ƿ��ջ���
    // �赱ǰ�����ջʱ����Ϊ0, ����ÿһ�ν�㱩¶��ջ��ʱ������1,
    // ������Ϊ2ʱ��ջ
    // ÿ�ν�㲻��Ҫ����ջ������Ҫ�����ֵջ
    // ͬ��û�ν���ջʱ��Ҫ������һ��㱩¶����

    std::stack<BiTNode *> S;
    std::stack<int> times;
    // �������ջ�����ü�����Ϊ0
    S.push(Tree);
    times.push(0);
    while (!S.empty()) {
        auto p = S.top();
        while (p) {
            S.push(p->lchild);
            times.push(0);
            p = p->lchild;
        }
        // ����Ч�ս���ջ
        S.pop();
        times.pop();
        times.top()++;
        while (times.top() == 2) {
            std::cout << S.top()->data;
            times.pop();
            S.pop();
            if(times.empty()) {
                break;
            }
            times.top()++;
        }
        if (!S.empty()) {
            S.push(S.top()->rchild);
            times.push(0);
        }
    }
}
