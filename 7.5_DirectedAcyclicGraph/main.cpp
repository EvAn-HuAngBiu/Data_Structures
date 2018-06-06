#include <iostream>
#include "ALGraph.h"
#include "CriticalPath.h"

using namespace std;

int main() {
    ALGraph graph(6, DG, new string[6]{"v1", "v2", "v3", "v4", "v5", "v6"});
    graph.InsertArc(0, 1);
    graph.InsertArc(0, 2);
    graph.InsertArc(0, 3);
    graph.InsertArc(2, 1);
    graph.InsertArc(2, 4);
    graph.InsertArc(3, 4);
    graph.InsertArc(5, 3);
    graph.InsertArc(5, 4);

    graph.TopologicalSort();
    cout << endl;
    graph.TopologicalSortDFS();
    cout << endl;


    ALGraph graph1(9, DN, new string[9]{"v1", "v2", "v3", "v4", "v5",
                                        "v6", "v7", "V8", "v9"});
    graph1.InsertArc(0, 1, 6);
    graph1.InsertArc(0, 2, 4);
    graph1.InsertArc(0, 3, 5);
    graph1.InsertArc(1, 4, 1);
    graph1.InsertArc(2, 4, 1);
    graph1.InsertArc(3, 5, 2);
    graph1.InsertArc(4, 6, 9);
    graph1.InsertArc(4, 7, 7);
    graph1.InsertArc(5, 7, 4);
    graph1.InsertArc(6, 8, 2);
    graph1.InsertArc(7, 8, 4);

    CriticalPath cp(graph1);
    cp.PrintCriticalPath();
    cout << endl;
    return 0;
}