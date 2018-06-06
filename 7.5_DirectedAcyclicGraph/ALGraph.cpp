/*********************************************************
 * FileName: ALGraph.cpp
 * Author:  Evan
 * Date: 27/05/2018
 * Description:
*********************************************************/

#include <stack>
#include "ALGraph.h"

ALGraph::ALGraph(int v, GraphKind k, std::string *data)
        : vexnum(v), arcnum(0), kind(k) {
    vertices = new VNode[MAX_VERTEX_NUM];
    for (int i = 0; i < vexnum; i++) {
        vertices[i].data = data[i];
        vertices[i].firstarc = nullptr;
    }
}

ALGraph::~ALGraph() {
    for (int i = 0; i < vexnum; i++) {
        auto p = vertices[i].firstarc;
        while (p) {
            auto temp = p;
            p = p->nextarc;
            delete temp;
        }
    }
    delete[] vertices;
}

void ALGraph::InsertArc(int srcVex, int dstVex, int weight) {
    // 利用头插法将弧插入结点表中, 构成srcVex->dstVex的弧
    auto *p = new ArcNode{dstVex, vertices[srcVex].firstarc, weight};
    vertices[srcVex].firstarc = p;
    ++arcnum;
    if (this->kind == UDG || this->kind == UDN) {
        // 如果是无向图, 则创建一个dstVex->srcVex的弧
        auto *q = new ArcNode{srcVex, vertices[dstVex].firstarc, weight};
        vertices[dstVex].firstarc = q;
        ++arcnum;
    }
}

std::ostream &operator<<(std::ostream &os, const ALGraph &g) {
    // 输出邻接表
    for (int i = 0; i < g.vexnum; i++) {
        os << g.vertices[i].data << "\t";
        auto p = g.vertices[i].firstarc;
        while (p) {
            os << p->adjvex << " -> ";
            p = p->nextarc;
        }
        os << std::endl;
    }
    return os;
}

void ALGraph::DFSTraverse() {
    // 图的深度优先遍历输出
    DepthFirstSearch dfs(*this);
}

void ALGraph::BFSTraverse() {
    BreadthFirstSearch(*this);
}

bool ALGraph::TopologicalSort() {
    // 拓扑排序
    // 拓扑排序要求图必须是有向图
    if (kind != DG) {
        return false;
    }
    // degree数组记录入度
    int degree[this->vexnum] {0};
    // 初始化degree数组, 遍历弧结点添加禄蠹
    for (int i = 0; i < vexnum; i++) {
        auto p = vertices[i].firstarc;
        while (p) {
            degree[p->adjvex]++;
            p = p->nextarc;
        }
    }
    std::stack<int> stack;
    int count = 0;
    for (int i = 0; i < vexnum; i++) {
        if (!degree[i]) {
            stack.push(i);
        }
    }
    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        std::cout << vertices[current].data << " ";
        count++;
        for(auto p = vertices[current].firstarc; p; p = p->nextarc) {
            if(!--degree[p->adjvex]) {
                stack.push(p->adjvex);
            }
        }
    }
    return (count == vexnum);
}

bool ALGraph::TopologicalSortDFS() {
    DepthFirstSearch dfs(*this);
    auto stack = dfs.GetTopologicalStack();
    int count = stack.size();
    while (!stack.empty()) {
        std::cout << this->vertices[stack.top()].data << " ";
        stack.pop();
    }
    return (count == this->vexnum);
}

/**
 * 图的深度优先搜素友元类DepthFirstSearch实现
 * */
DepthFirstSearch::DepthFirstSearch(const ALGraph &g) {
    visited = new bool[g.vexnum]{false};
    for (int i = 0; i < g.vexnum; i++) {
        if (!visited[i]) {
            dfs(g, i);
        }
    }
}

DepthFirstSearch::~DepthFirstSearch() {
    delete[] visited;
}

void DepthFirstSearch::dfs(const ALGraph &g, int v) {
    visited[v] = true;
    //std::cout << g.vertices[v].data << " ";
    for (ArcNode *w = g.vertices[v].firstarc; w; w = w->nextarc) {
        if (!visited[w->adjvex])
            dfs(g, w->adjvex);
    }
    // 适用于拓扑排序的DFS
    topological.push(v);
}

std::stack<int> DepthFirstSearch::GetTopologicalStack() {
    return topological;
}

/**
 * 图的广度优先搜素友元类DepthFirstSearch实现
 * */
BreadthFirstSearch::BreadthFirstSearch(const ALGraph &g) {
    visited = new bool[g.vexnum]{false};
    bfs(g);
}

BreadthFirstSearch::~BreadthFirstSearch() {
    delete[] visited;
}

void BreadthFirstSearch::bfs(const ALGraph &g) {
    for (int i = 0; i < g.vexnum; i++) {
        if (!visited[i]) {
            visited[i] = true;
            std::cout << g.vertices[i].data << " ";
            q.push(i);
            while (!q.empty()) {
                auto w = g.vertices[q.front()].firstarc;
                q.pop();
                for (; w; w = w->nextarc) {
                    if (!visited[w->adjvex]) {
                        visited[w->adjvex] = true;
                        std::cout << g.vertices[w->adjvex].data << " ";
                        q.push(w->adjvex);
                    }
                }
            }
        }
    }
}