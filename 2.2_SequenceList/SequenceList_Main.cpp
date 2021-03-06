// List.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SequenceList.h"
#include "SequenceList.cpp"
#include <iostream>
using namespace std;

bool equal(int src, int cmp);

int main()
{
#pragma region 正常工作测试

    SequenceList<int> L;  //测试：构造函数
    
    cout << (L.ListEmpty() == OK ? "空线性表" : "非空线性表") << endl;   //Empty测试 -->空
    for (int i = 1; i <= 5; i++)    //ListInsert测试
        L.ListInsert(i, i * 2);
    L.Display(); //Display输出测试 --> 2 4 6 8 10
    cout << (L.ListEmpty() == OK ? "空线性表" : "非空线性表") << endl;   //Empty测试 -->非空
    cout << L.ListLength() << endl; //Length测试 --> 5
    cout << L.GetElem(3) << endl;   //GetElem测试 --> 6
    cout << L.LocateElem(4, equal) << endl; //LocatElem测试 --> 2
    cout << L.PriorElem(6) << endl; //ProiorElement测试 --> 4
    cout << L.NextElem(6) << endl;  //NextElement测试 --> 8
    L.ListInsert(3, 5);     //Insert测试, 在第3个位置插入数5
    cout << "插入后结果输出, 插入后表长: " << L.ListLength() << endl;
    L.Display();
    cout << "插入后结果输出结束" << endl;
    cout << "删除后结果输出, 删除后表长: " << L.ListLength() << ", 删除元素: " << L.ListDelete(5) << endl;
    L.Display();
    cout << "删除后结果输出结束" << endl;
    L.ClearList();   //Clear测试
    cout << (L.ListEmpty() == OK ? "空线性表" : "非空线性表") << endl;
#pragma endregion

#pragma region 容量重分配测试
    system("cls");  //临时清屏
    SequenceList<int> test;

    for (int i = 1; i < 12; i++)
        test.ListInsert(i, i * 2);
    test.Display();


#pragma endregion

    return 0;
}

bool equal(int src, int cmp) { return src == cmp; }