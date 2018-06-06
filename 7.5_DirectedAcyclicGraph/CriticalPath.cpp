/*********************************************************
 * FileName: CriticalPath.cpp
 * Author:  Evan
 * Date: 03/06/2018
 * Description:
*********************************************************/

#include "CriticalPath.h"

CriticalPath::CriticalPath(const ALGraph &g) : graph(g) {
    ve = new int[g.vexnum] {0};
    vl = new int[g.vexnum];
}

CriticalPath::~CriticalPath() {
    delete[] ve;
    delete[] vl;
}

bool CriticalPath::Topological() {
    int degree[graph.vexnum] {0};
    int count = 0;
    std::stack<int> stack;
    // 求各顶点入度
    for (int i = 0;i < graph.vexnum; i++) {
        auto p = graph.vertices[i].firstarc;
        while (p) {
            degree[p->adjvex]++;
            p = p->nextarc;
        }
    }
    // 入度为0的结点入栈保存
    for (int i = 0; i < graph.vexnum; i++) {
        if (!degree[i]) {
            stack.push(i);
        }
    }

    while (!stack.empty()) {
        int k = stack.top();
        vex.push(k);
        stack.pop();
        count++;
        for (auto p = graph.vertices[k].firstarc; p; p = p->nextarc) {
            if (!--degree[p->adjvex]) {
                stack.push(p->adjvex);
            }
            if (ve[k] + p->weight > ve[p->adjvex]) {
                ve[p->adjvex] = ve[k] + p->weight;
            }
        }
    }
    return (count == graph.vexnum);
}

void CriticalPath::CriticalAct() {
    for (int i = 0; i < graph.vexnum; i++) {
        vl[i] = ve[vex.top()];
    }
    while (!vex.empty()) {
        int current = vex.top();
        vex.pop();
        auto p = graph.vertices[current].firstarc;
        while (p) {
            int k = p->adjvex;
            if (vl[k] - p->weight < vl[current]) {
                vl[current] = vl[k] - p->weight;
            }
            p = p->nextarc;
        }
    }
}

void CriticalPath::PrintCriticalPath() {
    if(!this->Topological()) {
        std::cerr << "Not a valid graph" << std::endl;
        return;
    }
    CriticalAct();
    std::cout << "Critical activities : " << std::endl;
    for(int i = 0; i < graph.vexnum; i++) {
        if (ve[i] == vl[i]) {
            std::cout << graph.vertices[i].data << " ";
        }
    }
}
