#include <iostream>
#include "SqList.cpp"
using namespace std;

int main() {
    //测试用例

    SqList<int> list;    //初始化顺序表, 调用默认构造函数
    for(int i = 1; i < 6; i++) {
        //循环插入元素, 每次都插入在表尾, 值为索引的2倍
        list.insertList(i, i * 2);
    }
    list.display();    //输出顺序表
    //查找顺序表中存在和不存在的元素, 并输出其索引
    cout << list.findList(8) << " " << list.findList(9) << endl;
    //删除顺序表中的值6和不存在的值7, 并打印删除后表内结果
    list.deleteList1(6);
    list.deleteList1(7);
    list.display();
    //删除顺序表中第3个的元素, 并打印删除后表内的结果
    cout << list.deleteList2(3) << endl;
    list.display();
    //如果索引越界, 那么会捕捉到异常
    try{
        cout << list.deleteList2(7) << endl;
    }
    catch(const char *msg) {
        cout << msg << endl;
    }
    //合并顺序表
    SqList<int> list2;
    list2.insertList(1, 2);
    list2.insertList(2, 3);
    list2.insertList(3, 5);
    list2.insertList(4, 4);
    list2.insertList(5, 9);
    list2.insertList(6, 8);
    list.unionList(list2);
    list.display();
    //区间删除, 删除元素大小在[3,6)的元素
    SqList<int> list3;
    list3.insertList(1, 2);
    list3.insertList(2, 6);
    list3.insertList(3, 3);
    list3.insertList(4, 7);
    list3.insertList(5, 5);
    list3.insertList(6, 4);
    list3.insertList(7, 2);
    list3.insertList(8, 8);
    list3.deleteBetween(3, 6);
    list3.display();
    return 0;
}