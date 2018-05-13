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
    // 必须按照先序顺序输入
    // 输入样例: -+a  *b  -c  d  /e  f  #
    // 当处于叶节点时，需要用两个空格来设置子节点为空

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
    // 先序递归遍历当前二叉树，直接调用递归函数
    preOrderPrint(this->Tree);
}

void BinaryTree::inOrderPrint() const {
    // 中序递归遍历当前二叉树，直接调用递归函数
    inOrderPrint(this->Tree);
}

void BinaryTree::postOrderPrint() const {
    // 后序递归遍历当前二叉树，直接调用递归函数
    postOrderPrint(this->Tree);
}

void BinaryTree::preOrderPrint(const BinaryTree::BiTNode *cur) const {
    // 先序遍历的递归函数
    if (cur) {
        std::cout << cur->data;
        preOrderPrint(cur->lchild);
        preOrderPrint(cur->rchild);
    }
}

void BinaryTree::inOrderPrint(const BinaryTree::BiTNode *cur) const {
    // 中序遍历的递归函数
    if (cur) {
        inOrderPrint(cur->lchild);
        std::cout << cur->data;
        inOrderPrint(cur->rchild);
    }
}

void BinaryTree::postOrderPrint(const BinaryTree::BiTNode *cur) const {
    // 后序遍历的递归函数
    if (cur) {
        postOrderPrint(cur->lchild);
        postOrderPrint(cur->rchild);
        std::cout << cur->data;
    }
}

void BinaryTree::preOrderPrint_NonRecursive() const {
    if (!Tree) {
        // 空树
        return;
    }
    // 非递归实现二叉树前序遍历(DLR)
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
    // 中序非递归遍历(LDR)
    if (!Tree) {
        // 空树
        return;
    }
    std::stack<BiTNode *> S;
    // 根结点入栈保存
    S.push(Tree);
    while (!S.empty()) {
        auto p = S.top();
        while (p) {
            p = S.top()->lchild;
            S.push(p);
        }
        // 空结点退栈
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
    // 中序非递归遍历—方法2(LDR)
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
    // 利用辅助指针的后序遍历, cur指向当前处理的结点，pre指向上一个处理的结点
    // 输出的条件：1. 当前结点没有左孩子和右孩子
    //             2. 当前结点的孩子已经被访问过，即pre是cur的子结点
    // 此时将栈顶结点出栈并输出
    // 否则 应该先将右孩子再将左孩子入栈保存

    BiTNode *cur, *pre = nullptr;
    std::stack<BiTNode *> S;
    // 将根结点入栈保存
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
    // 利用辅助计数栈来指示当前栈顶结点是否出栈输出
    // 设当前结点入栈时计数为0, 后续每一次结点暴露在栈顶时计数加1,
    // 当计数为2时出栈
    // 每次结点不仅要入结点栈，还需要入计数值栈
    // 同理没次结点出栈时还要设置下一结点暴露次数

    std::stack<BiTNode *> S;
    std::stack<int> times;
    // 根结点入栈，并置计数置为0
    S.push(Tree);
    times.push(0);
    while (!S.empty()) {
        auto p = S.top();
        while (p) {
            S.push(p->lchild);
            times.push(0);
            p = p->lchild;
        }
        // 遇无效空结点出栈
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
