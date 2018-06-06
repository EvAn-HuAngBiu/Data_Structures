#pragma once
/*********************************************************
 * FileName: UDGForest.h
 * Author:  Evan
 * Date: 28/05/2018
 * Description:
*********************************************************/

#ifndef INC_7_2_GRAPHSTORAGE_UDGFOREST_H
#define INC_7_2_GRAPHSTORAGE_UDGFOREST_H

#include "ALGraph.h"

typedef struct CSNode {
    std::string data;
    CSNode *firstchild;
    CSNode *nextsibling;

    CSNode(const std::string &d = "", CSNode *f = nullptr, CSNode *n = nullptr)
    {
        data = d;
        firstchild = f;
        nextsibling = n;
    }
} *CSTree;

class UDGForest {
private:
    bool *visited;

    const ALGraph &G;
public:
    explicit UDGForest(const ALGraph &g) : G(g) {
        visited = new bool[g.vexnum]{false};
    }

    void DFSForest(CSTree &t) const;

    void DFSTree(int v, CSTree &t) const;
};


#endif //INC_7_2_GRAPHSTORAGE_UDGFOREST_H
