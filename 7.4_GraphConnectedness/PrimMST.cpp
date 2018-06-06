/*********************************************************
 * FileName: PrimMST.cpp
 * Author:  Evan
 * Date: 02/06/2018
 * Description: Prim算法实现
*********************************************************/

#include "PrimMST.h"

PrimMST::PrimMST(const ALGraph &g) : graph(g) {
    // 默认将0号结点作为最小生成树的根结点
    closedge = new PrimArray[g.vexnum];
    // 已加入树的结点权重置0
    closedge[0].lowcost = 0;
    /* 初始化辅助数组, 即将0号结点的所有相邻结点的名字和权重加入数组
     不是0号结点相邻结点的，不添加名字，权重默认为65535(INFINITE) */
    // i指示相邻结点的表结点
    auto i = g.vertices[0].firstarc;
    // j指示相邻结点在邻接表中的位置索引
    int j = i->adjvex;
    while (i) {
        // 依附在该结点的已处理的结点显然是0号结点
        closedge[j].adjvex = g.vertices[0].data;
        // 设置权重
        closedge[j].lowcost = i->weight;
        i = i->nextarc;
        if (i) {
            j = i->adjvex;
        }
    }
    MST_Prim();
}

void PrimMST::MST_Prim() {
    // 输出已处理的第一个结点, 即0号结点
    std::cout << graph.vertices[0].data << " ";
    // 保存总权重
    int total = 0;
    // 循环处理剩余的所有结点
    for (int i = 1; i < graph.vexnum; i++) {
        // 获取当前最小权的结点索引
        int k = GetMinimum();
        // 输出当前最小权结点
        std::cout << graph.vertices[k].data << " ";
        total += closedge[k].lowcost;
        // 当前结点处理完毕, 权重置0
        closedge[k].adjvex = "";
        closedge[k].lowcost = 0;

        /* 更新辅助数组, 重新设置权, 只需要设置当前添加的结点即可
         * 其余结点的权不可能改变或可能与当前结点连通 */
        // 遍历当前结点的所有邻边
        auto edge = graph.vertices[k].firstarc;
        while (edge) {
            // 获取邻边权重
            int next = edge->adjvex;
            if (edge->weight < closedge[next].lowcost) {
                // 当前邻边权重小于已有权重, 修改
                closedge[next].adjvex = graph.vertices[k].data;
                closedge[next].lowcost = edge->weight;
            }
            // 下一边
            edge = edge->nextarc;
        }
    }
}

int PrimMST::GetMinimum() {
    // 最小权索引
    int minIndex = 1;
    while (closedge[minIndex].lowcost == 0) {
        minIndex++;
    }
    for (int i = 1; i < graph.vexnum; i++) {
        if (closedge[i].lowcost == 0) {
            continue;
        } else if (closedge[i].lowcost < closedge[minIndex].lowcost) {
            minIndex = i;
        }
    }
    return minIndex;
}
