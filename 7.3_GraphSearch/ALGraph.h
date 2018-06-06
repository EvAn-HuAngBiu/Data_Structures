#pragma once
/*********************************************************
 * FileName: ALGraph.h
 * Author:  Evan
 * Date: 27/05/2018
 * Description: 以邻接表存储的图的实现
*********************************************************/

#ifndef INC_7_2_GRAPHSTORAGE_ALGRAPH_H
#define INC_7_2_GRAPHSTORAGE_ALGRAPH_H

#include <string>
#include <iostream>
#include <queue>

const unsigned int MAX_VERTEX_NUM = 20;
const int INFINITE = 65535;

struct ArcNode {
    int adjvex;    // 该弧指向的顶点位置
    ArcNode *nextarc;    // 下一条弧位置
    int weight;    // 权重
};

struct VNode {
    std::string data;    // 顶点信息
    ArcNode *firstarc;    // 第一条弧结点
};

enum GraphKind {
    DG, DN, UDG, UDN
};    // {有向图,有向网,无向图,无向网}

class ALGraph {
private:
    VNode *vertices;    // 邻接表(存储所有顶点)
    int vexnum;    // 顶点数
    int arcnum;    // 弧数
    GraphKind kind;    // 图的类型
    friend class DepthFirstSearch;

    friend class BreadthFirstSearch;

public:
    ALGraph(int v, GraphKind k, std::string data[]);

    virtual ~ALGraph();

    void InsertArc(int srcVex, int dstVex, int weight = INFINITE);

    void DFSTraverse();

    void BFSTraverse();

    friend std::ostream &operator<<(std::ostream &, const ALGraph &);
};

/**
 * 用于图的深度优先搜索友元类
 * */
class DepthFirstSearch {
private:
    bool *visited;
public:
    explicit DepthFirstSearch(const ALGraph &);

    virtual ~DepthFirstSearch();

    void dfs(const ALGraph &, int);
};

/**
 * 用于图的广度优先搜索友元类
 * */
class BreadthFirstSearch {
private:
    bool *visited;
    std::queue<int> q;
public:
    explicit BreadthFirstSearch(const ALGraph &);

    virtual ~BreadthFirstSearch();

    void bfs(const ALGraph &);
};


#endif //INC_7_2_GRAPHSTORAGE_ALGRAPH_H
