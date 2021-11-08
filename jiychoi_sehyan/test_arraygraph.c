#include "arraygraph.h"

int main()
{
	ArrayGraph *graph;

	// 0 - 3
	// | 
	// 1 - 2

	graph = createArrayGraph(7);
	for (int i = 0; i < 7; i++) {
		addVertexAG(graph, i);
	}
	addEdgeAG(graph, 0, 1);
	addEdgeAG(graph, 0, 2);
	addEdgeAG(graph, 1, 3);
	addEdgeAG(graph, 1, 4);
	addEdgeAG(graph, 3, 7);
	addEdgeAG(graph, 2, 5);
	addEdgeAG(graph, 2, 6);
	addEdgeAG(graph, 4, 5);
	
	displayArrayGraph(graph);
	deleteArrayGraph(graph);
	// system("leaks a.out");
	return (0);
}