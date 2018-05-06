//
// Created by Evan on 2018/5/5.
//

#include "SparseMatrix.h"
#include <cmath>

template<typename T>
SparseMatrix<T>::SparseMatrix() {
    mu = nu = tu = 0;
    data = nullptr;
}

template<typename T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix::Triple *data,
                              int mu, int nu, int tu) {
    this->mu = mu;    // 行数
    this->nu = nu;    // 列数
    this->tu = tu;    // 非零元数, 即三元组长度
    this->data = new Triple[tu + 1];
    for (int i = 1; i <= tu; i++) {
        this->data[i] = data[i - 1];
    }
    // 计算rpos数组
    rpos = new int[this->tu + 1] {0};
    for (int i = 1; i <= this->tu; i++) {
        rpos[i] = 1;
    }
    for (int i = 1; i <= tu; i++) {
        for (int j = this->data[i].row + 1; j <= this->tu; j++) {
            rpos[j]++;
        }
    }
}

template<typename T>
SparseMatrix<T>::~SparseMatrix() {
    if (data) {
        delete[] data;
    }
    if (rpos) {
        delete[] rpos;
    }
}

template<typename Type>
std::ostream &operator<<(std::ostream &os, const SparseMatrix<Type> &s) {
    os << "\tRow\tLine\tValue" << std::endl;
    for (int i = 1; i <= s.tu; i++) {
        os << "\t" << s.data[i].row << "\t" << s.data[i].line
           << "\t" << s.data[i].ele << std::endl;
    }
    return os;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::add(const SparseMatrix &other) const {
    return SparseMatrix<T>();
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::sub(const SparseMatrix &other) const {
    return SparseMatrix<T>();
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::mul(const SparseMatrix &other) const {
    // 矩阵乘法, i行k列和k行j列矩阵相乘得到i行j列矩阵
    if (this->nu != other.mu) {
        // 行数和列数不相等, 不能相乘
        throw std::logic_error("Matrix with different row and line cannot be multiplied");
    }
    // 初始化一个结果三元组数组
    int maxsize = std::max(this->tu, other.tu) + 1;
    Triple *newdata = new Triple[maxsize];
    int tu = 0;
    if (this->tu * other.tu) {

        // 乘积结果为非零矩阵
        for (int arow = 1; arow <= this->mu; arow++) {
            // 处理矩阵a的每一行
            int ctemp[maxsize] {0};
            // 计算该行非零元素的数目, 即遍历的终点
            // 如果该行不是最后一行则遍历到下一行的非零首元前一位
            // 否则遍历到最后一个元素下一位
            int tp = (arow < this->mu ? rpos[arow + 1] : this->tu + 1);
            for (int p = rpos[arow]; p < tp; p++) {
                // 处理一列
                int brow = this->data[p].line;
                int t = (brow < other.mu ? other.rpos[brow + 1] : other.tu + 1);
                for (int q = other.rpos[brow]; q < t; q++) {
                    ctemp[other.data[q].line] += other.data[q].ele * this->data[p].ele;
                }
            }
            for (int k = 1; k <= other.nu; k++) {
                if (ctemp[k]) {
                    newdata[tu].row = arow;
                    newdata[tu].line = k;
                    newdata[tu].ele = ctemp[k];
                    tu++;
                }
            }
        }
    }
    SparseMatrix<T> result(newdata, this->mu, other.nu, tu);
    return result;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::transpose() const {
    // 将m行n列的矩阵转置为n行m列的矩阵
    Triple *newdata = new Triple[tu + 1];
    SparseMatrix<T> result(newdata, this->nu, this->mu, this->tu);
    if (this->tu) {
        // 如果存在非零元
        // index保存转置矩阵的数量和索引
        int index = 1;
        for (int col = 1; col <= this->nu; col++) {
            // 处理列号和col匹配的三元组
            for (int i = 1; i <= this->tu; i++) {
                // 遍历所有三元组寻找列号为col的三元组
                if (data[i].line == col) {
                    // 如果列号匹配, 交换行序和列序
                    result.data[index].row = this->data[i].line;
                    result.data[index].line = this->data[i].row;
                    result.data[index].ele = this->data[i].ele;
                    index++;
                }
            }
        }
    }
    return result;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::fastTranspose() const {
    Triple *newdata = new Triple[tu];
    SparseMatrix<T> result(newdata, this->nu, this->mu, this->tu);
    if (this->tu) {
        // 设置每列第一个非零元的位置数组
        int cpot[this->nu + 1] {0};
        for (int i = 1; i <= this->tu; i++) {
            cpot[i] = 1;
        }
        // 扫描数组
        for (int i = 1; i <= this->tu; i++) {
            for (int j = this->data[i].line + 1; j < this->tu ; j++) {
                // 将当前列之后所有列的首个非零元位置加1
                // 相当于在前一列添加了一个元素, 后序索引+1
                cpot[j]++;
            }
        }
        // 转置
        for (int i = 1; i <= this->tu; i++) {
            int pos = cpot[this->data[i].line];
            result.data[pos].row = this->data[i].line;
            result.data[pos].line = this->data[i].row;
            result.data[pos].ele = this->data[i].ele;
            cpot[this->data[i].line - 1]++;
        }
    }
    return result;
}
