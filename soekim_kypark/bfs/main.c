#include "BFS.h"
#include "linkedgraph.h"

int main ()
{
    LinkedGraph* pGraph = createLinkedGraph(9);
    for(int i=0; i<9; i++)
        addVertexLG(pGraph, i);
    addEdgeLG(pGraph, 0, 1);
    addEdgeLG(pGraph, 0, 2);
    addEdgewithWeightLG(pGraph, 2, 3, 8);
    addEdgewithWeightLG(pGraph, 3, 4, 3);
    addEdgeLG(pGraph, 2, 5);
    addEdgeLG(pGraph, 5, 6);
    addEdgeLG(pGraph, 6, 7);
    addEdgeLG(pGraph, 4, 7);
    //addEdgeLG(pGraph, 4, 7);
    //removeEdgeLG(pGraph, 0, 2);
    //traversal_DFS(pGraph, 0);
    //printf("\n");
    // traversal_DFS2(pGraph, 0);
    printf("\n");
    // displayLinkedGraph(pGraph); //need to debug, sometimes segfault
    bfsTraverse(pGraph);
    return (0);
}