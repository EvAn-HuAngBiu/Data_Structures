/*********************************************************
 * FileName: UDGForest.cpp
 * Author:  Evan
 * Date: 28/05/2018
 * Description: 求无向图的连通分量和生成树（森林）
 *              以二叉树表示
*********************************************************/

#include "UDGForest.h"

void UDGForest::DFSForest(CSTree &t) const {
    t = nullptr;
    CSTree  q = nullptr;
    for (int v = 0; v < G.vexnum; v++) {
        if (!visited[v]) {
            auto p = new CSNode(G.vertices[v].data, nullptr, nullptr);
            if (!t) {
                t = p;
            } else {
                q->nextsibling = p;
            }
            q = p;
            DFSTree(v, p);
        }
    }
}

void UDGForest::DFSTree(int v, CSTree &t) const {
    visited[v] = true;
    bool first = true;
    CSTree q = nullptr;
    for (auto k = G.vertices[v].firstarc; k; k = k->nextarc) {
        int w = k->adjvex;
        if (!visited[w]) {
            auto p = new CSNode(G.vertices[w].data, nullptr, nullptr);
            if (first) {
                t->firstchild = p;
                first = false;
            } else {
                q->nextsibling = p;
            }
            q = p;
            DFSTree(w, q);
        }
    }
}
