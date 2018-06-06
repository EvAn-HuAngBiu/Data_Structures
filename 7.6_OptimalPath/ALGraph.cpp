/*********************************************************
 * FileName: ALGraph.cpp
 * Author:  Evan
 * Date: 27/05/2018
 * Description:
*********************************************************/

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

void ALGraph::Dijkstra() {
    // 基于邻接表的Dijkstra算法, 复杂度O(n^2)
    int dis[vexnum];
    bool visited[vexnum] = {false};
    visited[0] = true;
    for (int i = 0; i < vexnum; i++) {
        // 初始化数组
        dis[i] = INFINITE;
    }
    for (auto p = vertices[0].firstarc; p; p = p->nextarc) {
        // 初始化路径
        dis[p->adjvex] = p->weight;
    }
    for (int i = 1; i < vexnum; i++) {
        int min = INFINITE, minIndex = 0;
        for (int w = 0; w < vexnum; w++) {
            if (!visited[w] && dis[w] < min) {
                min = dis[w];
                minIndex = w;
            }
        }
        visited[minIndex] = true;
        for (auto p = vertices[minIndex].firstarc; p; p = p->nextarc) {
            if (p->weight + dis[minIndex] < dis[p->adjvex]) {
                dis[p->adjvex] = p->weight + dis[minIndex];
            }
        }
    }
    for(int i : dis) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void ALGraph::Floyd() {
    // Floyd算法
    int dis[vexnum][vexnum], pos[vexnum][vexnum];

    for(int i = 0;i < vexnum; i++) {
        for (int j = 0; j < vexnum; j++) {
            dis[i][j] = INFINITE;
            pos[i][j] = j;
        }
    }

    for(int i = 0; i < vexnum; i++) {
        for (auto p = vertices[i].firstarc; p; p = p->nextarc) {
            dis[i][p->adjvex] = p->weight;
        }
    }

    for (int i = 0; i < vexnum; i++) {
        // 第一层循环 指定中间值
        for (int row = 0; row < vexnum; row++) {
            // 第二层循环定位处理元素
            for (int col = 0; col < vexnum; col++) {
                if (dis[row][i] + dis[i][col] < dis[row][col]) {
                    dis[row][col] = dis[row][i] + dis[i][col];
                    pos[row][col] = pos[row][i];
                }
            }
        }
    }

    for (int row = 0; row < vexnum; row++) {
        for (int col = 0; col < vexnum; col++) {
            std::cout << dis[row][col] << "\t";
        }
        std::cout << std::endl;
    }

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
    std::cout << g.vertices[v].data << " ";
    for (ArcNode *w = g.vertices[v].firstarc; w; w = w->nextarc) {
        if (!visited[w->adjvex])
            dfs(g, w->adjvex);
    }
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