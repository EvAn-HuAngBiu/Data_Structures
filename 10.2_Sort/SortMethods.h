//
// Created by Evan on 25/06/2018.
//

#ifndef INC_10_2_SORT_SORTMETHODS_H
#define INC_10_2_SORT_SORTMETHODS_H

template<typename T>
class SortMethods {
private:
    void static exchange(T *src, int from, int to);

    // 获得区间最小值的索引
    int static getMin(T *src, int len, int from);

    // 二分查找, 返回插入位置的索引
    int static binarySearch(T *src, int lo, int hi, T target);

    void static quickSort(T *src, int lo, int hi);

    int static partition(T *src, int lo, int hi);

    void static quick3WaySort(T *src, int lo, int hi);

public:
    // 直接插入排序(带哨兵, 0号单元不参与排序)
    void static insertSort(T *src, int len);

    // 直接插入排序(带哨兵, 全部元素都参与排序)
    void static insertSort2(T *src, int len);

    // 折半插入排序
    void static binaryInsertSort(T *src, int len);

    // 选择排序
    void static selectSort(T *src, int len);

    // 希尔排序
    void static shellSort(T *src, int len);

    // 冒泡排序
    void static bubbleSort(T *src, int len);

    // 快速排序
    void static quickSort(T *src, int len);

    // 三向切分的快速排序
    void static quick3WaySort(T *src, int len);
};


template<typename T>
void SortMethods<T>::exchange(T *src, int from, int to) {
    T temp = src[from];
    src[from] = src[to];
    src[to] = temp;
}

template<typename T>
int SortMethods<T>::getMin(T *src, int len, int from) {
    int min = from;
    for (int j = from + 1; j < len; j++) {
        if (src[j] < src[min]) {
            min = j;
        }
    }
    return min;
}

template<typename T>
int SortMethods<T>::binarySearch(T *src, int lo, int hi, T target) {
    // 二分查找, 查找长度为len数组src中[lo, hi)区间元素下标
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (src[mid] < target) {
            lo = mid + 1;
        } else if (src[mid] > target) {
            hi = mid;
        } else {
            return mid;
        }
    }
    return hi;
}

template<typename T>
void SortMethods<T>::insertSort(T *src, int len) {
    // 设置哨兵, 0号位不参与排序
    for (int i = 2; i <= len; i++) {
        if (src[i] < src[i - 1]) {
            src[0] = src[i];    // 设置哨兵
            src[i] = src[i - 1];
            int j = i - 2;
            while (src[0] < src[j]) {
                src[j + 1] = src[j];
                --j;
            }
            src[j + 1] = src[0];
        }
    }
}

template<typename T>
void SortMethods<T>::insertSort2(T *src, int len) {
    exchange(src, 0, getMin(src, len, 0));    // 设置哨兵为最小元素
    for (int i = 2; i < len; i++) {
        if (src[i] < src[i - 1]) {
            T temp = src[i];
            int j = i;
            while (temp < src[j - 1]) {
                src[j] = src[j - 1];
                j--;
            }
            src[j] = temp;
        }
    }
}

template<typename T>
void SortMethods<T>::binaryInsertSort(T *src, int len) {
    // 折半插入排序
    for (int i = 1; i < len; i++) {
        T current = src[i];
        int index = binarySearch(src, 0, i, current);
        int j = i;
        while (j > index) {
            src[j] = src[j - 1];
            --j;
        }
        src[index] = current;
    }
}

template<typename T>
void SortMethods<T>::selectSort(T *src, int len) {
    for (int i = 0; i < len; i++) {
        int min = getMin(src, len, i);
        exchange(src, i, min);
    }
}

template<typename T>
void SortMethods<T>::shellSort(T *src, int len) {
    // 希尔排序
    int h = 1;
    while (h < len / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < len; i++) {
            for (int j = i; j >= h && src[j] < src[j - h]; j -= h) {
                exchange(src, j, j - h);
            }
        }
        h /= 3;
    }
}

template<typename T>
void SortMethods<T>::bubbleSort(T *src, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1;j++) {
            if (src[j + 1] < src[j]) {
                exchange(src, j, j + 1);
            }
        }
    }
}

template<typename T>
void SortMethods<T>::quickSort(T *src, int len) {
    quickSort(src, 0, len - 1);
}

template<typename T>
void SortMethods<T>::quickSort(T *src, int lo, int hi) {
    if (lo < hi) {
        int p = partition(src, lo, hi);
        quickSort(src, lo, p - 1);
        quickSort(src, p + 1, hi);
    }
}

template<typename T>
int SortMethods<T>::partition(T *src, int lo, int hi) {
    T pivotkey = src[lo];
    while (lo < hi) {
        while (lo < hi && src[hi] >= pivotkey) {
            --hi;
        }
        src[lo] = src[hi];
        while (lo < hi && src[lo] <= pivotkey) {
            ++lo;
        }
        src[hi] = src[lo];
    }
    src[lo] = pivotkey;
    return lo;
}

template<typename T>
void SortMethods<T>::quick3WaySort(T *src, int len) {
    quick3WaySort(src, 0, len - 1);
}

template<typename T>
void SortMethods<T>::quick3WaySort(T *src, int lo, int hi) {
    if (lo < hi) {
        T key = src[lo];
        // [lo,lt - 1]区间元素小于key, [lt,i - 1]区间元素等于key, [i,gt]区间元素不确定
        // [gt + 1, hi]区间元素大于key
        int lt = lo, gt = hi, i = lo + 1;
        while (i <= gt) {
            if (src[i] < key) {
                exchange(src, lt++, i++);
            } else if (src[i] > key) {
                exchange(src, i, gt--);
            } else {
                i++;
            }
        }
        quick3WaySort(src, lo, lt - 1);
        quick3WaySort(src, gt + 1, hi);
    }
}


#endif //INC_10_2_SORT_SORTMETHODS_H
