#pragma once
/*********************************************************
 * FileName: CriticalPath.h
 * Author:  Evan
 * Date: 03/06/2018
 * Description:
*********************************************************/

#ifndef INC_7_5_DIRECTEDACYCLICGRAPH_CRITICALPATH_H
#define INC_7_5_DIRECTEDACYCLICGRAPH_CRITICALPATH_H


#include "ALGraph.h"

class CriticalPath {
private:
    const ALGraph &graph;
    int *ve;    // 最早开始时间
    int *vl;    // 最迟开始时间
    std::stack<int> vex;    // 拓扑排序顶点栈
public:
    explicit CriticalPath(const ALGraph &);

    virtual ~CriticalPath();

    bool Topological();

    void CriticalAct();

    void PrintCriticalPath();
};


#endif //INC_7_5_DIRECTEDACYCLICGRAPH_CRITICALPATH_H
