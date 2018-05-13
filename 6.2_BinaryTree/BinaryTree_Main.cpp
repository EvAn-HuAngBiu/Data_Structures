#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree tree;
    tree.preOrderCreate();

    cout << "�ݹ�ʵ�ֶ�����ǰ����� : ";
    tree.preOrderPrint();
    cout << endl;

    cout << "�ݹ�ʵ�ֶ������������ : ";
    tree.inOrderPrint();
    cout << endl;

    cout << "�ݹ�ʵ�ֶ������������ : ";
    tree.postOrderPrint();
    cout << endl;

    cout << "�ǵݹ�ʵ�ֶ�����ǰ����� : ";
    tree.preOrderPrint_NonRecursive();
    cout << endl;

    cout << "�ǵݹ�ʵ�ֶ������������������1 : ";
    tree.inOrderPrint_NonRecursive1();
    cout << endl;

    cout << "�ǵݹ�ʵ�ֶ������������������2 : ";
    tree.inOrderPrint_NonRecursive2();
    cout << endl;

    cout << "�ǵݹ�ʵ�ֶ������ĺ������������ָ�� : ";
    tree.postOrderPrint_NonRecursive1();
    cout << endl;

    cout << "�ǵݹ�ʵ�ֶ������ĺ�����������ø���ջ : ";
    tree.postOrderPrint_NonRecursive2();
    cout << endl;
    return 0;
}