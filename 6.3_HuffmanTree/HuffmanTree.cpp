//
// Created by Evan on 18/05/2018.
//

#include <iostream>
#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(unsigned int *w, unsigned int n) {
    // 构造一个哈夫曼树
    // 参数w: 存放n个字符的权值
    // 参数n: 字符总数
    HTree = new HTNode[2 * n];    // 初始化哈夫曼树数组, 0号单元未使用
    length = n;
    for (int i = 1; i <= n; i++) {
        HTree[i] = {w[i - 1], 0, 0, 0};
    }
    for (unsigned int i = n + 1; i < 2 * n; i++) {
        unsigned int s1 = 0, s2 = 0;
        select(i - 1, s1, s2);    // 搜索最小的权
        HTree[i] = {HTree[s1].weight + HTree[s2].weight, 0, s1, s2};
        HTree[s1].parent = i;
        HTree[s2].parent = i;
    }
}

void HuffmanTree::select(int i, unsigned int &s1, unsigned int &s2) {
    // 寻找最小和次小的数
    unsigned int min2 = 0;
    unsigned int min1 = 0;
    for (unsigned int j = 1; j <= i; j++) {
        // 第一次扫描找最小值
        if (HTree[j].parent) {
            // 结点已经被选择
            continue;
        }
        if (HTree[j].weight < HTree[min1].weight) {
            min1 = j;
        }
    }
    for (unsigned int j = 1; j <= i; j++) {
        // 第二次扫描找次小值
        if (j == min1 || HTree[j].parent) {
            continue;
        }
        if (HTree[j].weight < HTree[min2].weight) {
            min2 = j;
        }
    }
    s1 = min1;
    s2 = min2;
}

void HuffmanTree::huffmanCode(unsigned int n) {
    HCode = new std::string[n + 1];
    std::string cd(n, ' ');
    for (unsigned int i = 1; i <= n; i++) {
        auto start = n;
        for (unsigned int c = i, f = HTree[i].parent;
             f != 0; c = f, f = HTree[f].parent) {
            if (HTree[f].lchild == c) {
                cd[--start] = '0';
            } else {
                cd[--start] = '1';
            }
        }
        HCode[i] = cd.substr(start, n);
    }
}

void HuffmanTree::huffmanCode_FromRoot(unsigned int n) {
    auto HT = new HTNode[2 * n];
    for (int i = 1; i < 2 * n; i++) {
        // 创建一个副本
        HT[i] = {0, HTree[i].parent, HTree[i].lchild, HTree[i].rchild};
    }
    HCode = new std::string[n + 1];
    std::string cd(2 * n, ' ');
    int p = 2 * n - 1, cdlen = 0;
    while (p) {
        if (HT[p].weight == 0) {
            HT[p].weight = 1;
            if (HT[p].lchild) {
                p = HT[p].lchild;
                cd[cdlen++] = '0';
            } else if (!HT[p].rchild) {
                HCode[p] = cd.substr(0, cdlen);
            }
        } else if (HT[p].weight == 1) {
            HT[p].weight = 2;
            if (HT[p].rchild) {
                p = HT[p].rchild;
                cd[cdlen++] = '1';
            }
        } else {
            HT[p].weight = 0;
            p = HT[p].parent;
            --cdlen;
        }
    }
}

std::ostream &operator<<(std::ostream &os, HuffmanTree &h) {
    os << "Weight\tCode" << std::endl;
    for (int i = 1; i <= h.length; i++) {
        os << h.HTree[i].weight << "\t" << h.HCode[i] << std::endl;
    }
    return os;
}
