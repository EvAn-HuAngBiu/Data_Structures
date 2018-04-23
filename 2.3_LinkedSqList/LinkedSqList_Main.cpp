#include <iostream>
#include "LinkedSqList.cpp"

using namespace std;

int main() {
    LinkedSqList<int> list, list2;
    cout.setf(ios_base::boolalpha);
    cout << list.isEmpty() << endl;

    int arr1[5] = {1, 2, 3, 4, 5};
    list.createList_H(5, arr1);    //头插法插入(逆序插入)
    list.display();

    int arr2[5] = {6, 7, 8, 9, 10};
    list2.createList_L(5, arr2);    //尾插法插入(顺序插入)
    list2.display();

    list.insertList(3, 10);
    list.display();

    try {
        list.insertList(0, 1);    //非法插入位置
        //list.insertList(8, 22); //超长
    }
    catch (const char *error) {
        cerr << error << endl;
    }
    list.display();

    list.deleteList(5);
    list.display();

    try {
        list.deleteList(6);    //非法删除位置
    }
    catch (const char *error) {
        cerr << error << endl;
    }

    cout << list.findList(20) << " " << list.findList(1) << endl;

    //拆分奇偶数项
    LinkedSqList<int> even, odd;
    odd.createList_L(10, new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    odd.split(even);
    odd.display();
    even.display();

    cin.get();
    return 0;
}