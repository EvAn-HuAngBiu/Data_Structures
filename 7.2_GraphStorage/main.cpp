#include <iostream>
#include "ALGraph.h"

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
    graph.DFSTraverse();
    cout << endl;
    graph.BFSTraverse();
    return 0;
}