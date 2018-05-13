#pragma once
//
// 二叉树的二叉链表存储表示
// 所有遍历都只会打印出每个结点的值而不会修改内容
// 没有实现析构函数，本质即遍历销毁结点
// Created by Evan on 2018/5/13.
//

#ifndef INC_6_2_BINARYTREE_H
#define INC_6_2_BINARYTREE_H

class BinaryTree {
public:
    // 定义二叉树的结点
    struct BiTNode {
        char data;
        BiTNode *lchild;
        BiTNode *rchild;
    };

    // 先序递归创建二叉树, 对外接口
    void preOrderCreate();

    // 二叉树的递归先序遍历, 对外接口
    void preOrderPrint() const;

    // 二叉树的递归中序遍历, 对外接口
    void inOrderPrint() const;

    // 二叉树的递归后序遍历, 对外接口
    void postOrderPrint() const;

    // 二叉树的非递归先序遍历
    void preOrderPrint_NonRecursive() const;

    // 二叉树的非递归中序遍历
    void inOrderPrint_NonRecursive1() const;

    // 二叉树的非递归中序遍历，方法2
    void inOrderPrint_NonRecursive2() const;

    // 二叉树的非递归后序遍历
    void postOrderPrint_NonRecursive1() const;

    // 二叉树的非递归后序遍历，方法2
    void postOrderPrint_NonRecursive2() const;

private:
    // 根结点
    BiTNode *Tree;

    // 先序递归创建 递归函数声明
    void preOrderCreate(BiTNode *&);

    // 二叉树的递归遍历 递归函数声明
    void preOrderPrint(const BiTNode *) const;

    void inOrderPrint(const BiTNode *) const;

    void postOrderPrint(const BiTNode *) const;
};

#endif //INC_6_2_BINARYTREE_H
