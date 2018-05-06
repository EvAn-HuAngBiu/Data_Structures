#pragma once
//
// Created by Evan on 2018/5/5.
//

#ifndef INC_5_3_SPARSEMATRIX_H
#define INC_5_3_SPARSEMATRIX_H

#include <iostream>

template<typename T>
class SparseMatrix {
public:

    struct Triple {
        int row;     // 行下标
        int line;    // 列下标
        T ele;     // 存储元素
    public:
        explicit Triple(int r = 0, int l = 0, T e = 0) {
            row = r;
            line = l;
            ele = e;
        }
    };

    SparseMatrix();    // 初始化一个空稀疏矩阵

    SparseMatrix(const Triple *data, int mu, int nu, int tu);    // 初始化一个稀疏矩阵

    virtual ~SparseMatrix();    // 销毁稀疏矩阵

    // 打印矩阵
    template<typename Type>
    friend std::ostream &operator<<(std::ostream &, const SparseMatrix<Type> &);

    // 矩阵加法
    SparseMatrix<T> add(const SparseMatrix &other) const;

    // 矩阵减法
    SparseMatrix<T> sub(const SparseMatrix &other) const;

    // 矩阵乘法
    SparseMatrix<T> mul(const SparseMatrix &other) const;

    // 矩阵转置
    SparseMatrix<T> transpose() const;

    // 矩阵的快速转置
    SparseMatrix<T> fastTranspose() const;

private:
    int mu;    // 矩阵行数
    int nu;    // 矩阵列数
    int tu;    // 矩阵非零元个数
    Triple *data;    // 三元组数组基地址
    int *rpos;    // 各行第一个非零元的位置表
};

#endif //INC_5_3_SPARSEMATRIX_H
