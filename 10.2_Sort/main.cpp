#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <random>
#include <chrono>
#include "SortMethods.h"
using namespace std;

double timeTest(void (*function)(int *, int), int times) {
    // 测试排序算法时间
    int arr[5000];
    double sum = 0;
    for (int t = 0; t < times; t++) {
        for (int i = 0; i < 5000; i++) {
            arr[i] = i;
        }
        std::shuffle(begin(arr), end(arr), default_random_engine(
                static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count())));
        double start = clock();
        function(arr, 5000);
        double stop = clock();
        sum += (stop - start) / CLK_TCK;
    }
    return sum;
}

void beginTimeTest() {
    cout << "插入排序时间: " << timeTest(SortMethods<int>::insertSort, 100) << endl;
    cout << "插入排序2时间：" << timeTest(SortMethods<int>::insertSort2, 100) << endl;
    cout << "折半插入排序时间：" << timeTest(SortMethods<int>::binaryInsertSort, 100) << endl;
    cout << "选择排序时间：" << timeTest(SortMethods<int>::selectSort, 100) << endl;
    cout << "希尔排序时间：" << timeTest(SortMethods<int>::shellSort, 100) << endl;
    cout << "冒泡排序时间：" << timeTest(SortMethods<int>::bubbleSort, 100) << endl;
    cout << "快速排序时间: " << timeTest(SortMethods<int>::quickSort, 100) <<endl;
    cout << "三向切分快速排序时间: " << timeTest(SortMethods<int>::quick3WaySort, 100) <<endl;
}

int staticFind(int *src, int len, int key) {
    src[0] = key;
    int i = len;
    while (src[--i] != key);
    return i;
}

int main() {
    int arr1[] = {0, 7, 3, 2, 6, 1, 5, 4, 8};
    SortMethods<int>::insertSort(arr1, 8);
    for (int i = 1; i <= 8; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    int arr2[] = {7, 3, 2, 6, 1, 5, 4, 8};
    SortMethods<int>::insertSort2(arr2, 8);
    for (int i : arr2) {
        cout << i << " ";
    }
    cout << endl;

    int arr3[] = {7, 3, 2, 6, 1, 5, 4, 8};
    SortMethods<int>::binaryInsertSort(arr3, 8);
    for (int i : arr3) {
        cout << i << " ";
    }
    cout << endl;

    int arr4[] = {7, 3, 2, 6, 1, 5, 4, 8};
    SortMethods<int>::selectSort(arr4, 8);
    for (int i : arr4) {
        cout << i << " ";
    }
    cout << endl;

    int arr5[] = {7, 3, 2, 6, 1, 5, 4, 8};
    SortMethods<int>::shellSort(arr5, 8);
    for (int i : arr5) {
        cout << i << " ";
    }
    cout << endl;

    int arr6[] = {7, 3, 2, 6, 1, 5, 4, 8};
    SortMethods<int>::bubbleSort(arr6, 8);
    for (int i : arr6) {
        cout << i << " ";
    }
    cout << endl;

    int arr7[] = {49, 38, 65, 97, 76, 13, 27, 49};
    SortMethods<int>::quickSort(arr7, 8);
    for (int i : arr7) {
        cout << i << " ";
    }
    cout << endl;

    int arr8[] = {49, 38, 65, 97, 76, 13, 27, 49};
    SortMethods<int>::quick3WaySort(arr8, 8);
    for (int i : arr8) {
        cout << i << " ";
    }
    cout << endl;

    int arr9[] = {7, 3, 2, 6, 1, 5, 4, 8};
    cout << staticFind(arr9, 8, 7) << endl;
    //beginTimeTest();
    return 0;
}

