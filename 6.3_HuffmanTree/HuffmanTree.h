#pragma once
//
// Created by Evan on 18/05/2018.
//

#ifndef INC_6_3_HUFFMANTREE_HUFFMANTREE_H
#define INC_6_3_HUFFMANTREE_HUFFMANTREE_H


#include <string>

class HuffmanTree {
public:
    struct HTNode {
        unsigned int weight;    // 权重
        unsigned int parent;    // 父节点
        unsigned int lchild;
        unsigned int rchild;
    };

    HuffmanTree(unsigned int *w, unsigned int n);

    void select(int i, unsigned int &s1, unsigned int &s2);

    void huffmanCode(unsigned int n);

    void huffmanCode_FromRoot(unsigned int n);

    friend std::ostream &operator<<(std::ostream &, HuffmanTree &);

private:
    HTNode *HTree;    // 哈夫曼树基址
    int length;
    std::string *HCode;    // 哈夫曼编码表二维数组基址
};


#endif //INC_6_3_HUFFMANTREE_HUFFMANTREE_H
