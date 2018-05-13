#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree tree;
    tree.preOrderCreate();

    cout << "递归实现二叉树前序遍历 : ";
    tree.preOrderPrint();
    cout << endl;

    cout << "递归实现二叉树中序遍历 : ";
    tree.inOrderPrint();
    cout << endl;

    cout << "递归实现二叉树后序遍历 : ";
    tree.postOrderPrint();
    cout << endl;

    cout << "非递归实现二叉树前序遍历 : ";
    tree.preOrderPrint_NonRecursive();
    cout << endl;

    cout << "非递归实现二叉树中序遍历—方法1 : ";
    tree.inOrderPrint_NonRecursive1();
    cout << endl;

    cout << "非递归实现二叉树中序遍历—方法2 : ";
    tree.inOrderPrint_NonRecursive2();
    cout << endl;

    cout << "非递归实现二叉树的后序遍历—利用指针 : ";
    tree.postOrderPrint_NonRecursive1();
    cout << endl;

    cout << "非递归实现二叉树的后序遍历—利用辅助栈 : ";
    tree.postOrderPrint_NonRecursive2();
    cout << endl;
    return 0;
}