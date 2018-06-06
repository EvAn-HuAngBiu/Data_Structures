#include <iostream>
#include <string>
#include "ALGraph.h"

using namespace std;

int main() {
    ALGraph graph(6, DN, new string[6]{"v0", "v1", "V2", "v3", "v4", "v5"});
    graph.InsertArc(0, 2, 10);
    graph.InsertArc(0, 4, 30);
    graph.InsertArc(0, 5, 100);
    graph.InsertArc(1, 2, 5);
    graph.InsertArc(2, 3, 50);
    graph.InsertArc(3, 5, 10);
    graph.InsertArc(4, 3, 20);
    graph.InsertArc(4, 5, 60);

    cout << graph << endl;
    graph.Dijkstra();
    graph.Floyd();
    return 0;
}