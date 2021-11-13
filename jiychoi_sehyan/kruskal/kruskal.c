#include "kruskal.h"

#define MAX 6

int main()
{
	ArrayGraph *graph;
	graph = createArrayGraph(MAX);
	for (int i = 0; i < MAX; i++) {
		addVertexAG(graph, i);
	}

	addEdgewithWeightAG(graph, 2, 3, 1);
	addEdgewithWeightAG(graph, 3, 4, 1);
	addEdgewithWeightAG(graph, 1, 2, 2);
	addEdgewithWeightAG(graph, 0, 2, 3);
	addEdgewithWeightAG(graph, 0, 1, 4);
	addEdgewithWeightAG(graph, 3, 5, 5);
	addEdgewithWeightAG(graph, 4, 5, 6);
	printf("======\n");
	displayArrayGraph(graph);
	printf("=====\n");

	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		if (graph->pVertex[i] == TRUE) {
			
		}
	}

	deleteArrayGraph(graph);
	// system("leaks a.out");
	return (0);
}