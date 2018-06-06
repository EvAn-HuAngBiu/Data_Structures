#include <iostream>
#include "ALGraph.h"
#include "PrimMST.h"
#include "UDGForest.h"
using namespace std;

int main() {
    ALGraph graph(8, UDG, new string[8]{"v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8"});
    graph.InsertArc(0, 2);
    graph.InsertArc(0, 1);
    graph.InsertArc(1, 4);
    graph.InsertArc(1, 3);
    graph.InsertArc(2, 6);
    graph.InsertArc(2, 5);
    graph.InsertArc(3, 7);
    graph.InsertArc(4, 7);
    graph.InsertArc(5, 6);

    UDGForest u(graph);
    CSTree t = nullptr;
    u.DFSForest(t);

    // 测试Prim算法
    ALGraph graph2(6, UDN, new string[6]{"V1", "V2", "V3", "V4", "V5", "V6"});
    graph2.InsertArc(0,1,6);
    graph2.InsertArc(0,2,3);
    graph2.InsertArc(0,3,5);
    graph2.InsertArc(1,2,5);
    graph2.InsertArc(1,4,3);
    graph2.InsertArc(2,3,5);
    graph2.InsertArc(2,4,6);
    graph2.InsertArc(2,5,4);
    graph2.InsertArc(3,5,2);
    graph2.InsertArc(4,5,6);

    PrimMST p(graph2);
    return 0;
}