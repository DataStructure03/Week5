#include "linkedgraph.h"

int main()
{
	LinkedGraph *graph;

	graph = createLinkedGraph(8);
	for (int i = 0; i < 8; i++) {
		addVertexLG(graph, i);
	}
	// addEdgeLG(graph, 0, 1);
	// // addEdgeLG(graph, 1, 0);
	// addEdgeLG(graph, 0, 2);
	// // addEdgeLG(graph, 2, 0);
	// addEdgeLG(graph, 3, 0);
	// addEdgeLG(graph, 1, 2);
	// addEdgeLG(graph, 2, 3);
/*
** DFS
*/
	addEdgeLG(graph, 0, 1);
	addEdgeLG(graph, 0, 2);
	addEdgeLG(graph, 1, 3);
	addEdgeLG(graph, 1, 4);
	addEdgeLG(graph, 3, 7);
	addEdgeLG(graph, 2, 5);
	addEdgeLG(graph, 2, 6);
	addEdgeLG(graph, 4, 5);

	displayLinkedGraph(graph);
	deleteLinkedGraph(graph);
	// system("leaks a.out");
	return (0);
}