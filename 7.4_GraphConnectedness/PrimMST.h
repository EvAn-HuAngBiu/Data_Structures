#pragma once
/*********************************************************
 * FileName: PrimMST.h
 * Author:  Evan
 * Date: 02/06/2018
 * Description: 邻接表实现的图的最小生成树Prim算法
*********************************************************/

#ifndef INC_7_2_GRAPHSTORAGE_PRIMMST_H
#define INC_7_2_GRAPHSTORAGE_PRIMMST_H


#include <string>
#include "ALGraph.h"

class PrimMST {
private:
    const ALGraph &graph;

    struct PrimArray {
        std::string adjvex;
        int lowcost = INFINITE;
    } *closedge;
public:
    explicit PrimMST(const ALGraph &);

    void MST_Prim();

    int GetMinimum();
};


#endif //INC_7_2_GRAPHSTORAGE_PRIMMST_H
