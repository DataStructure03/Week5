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

	int **infoList;

	infoList = (int **)calloc(MAX, sizeof(int *));
	for (int i = 0; i < MAX; i++) {
		infoList[i] = (int *)calloc(sizeof(int), 3);
	}

	arrHeap *heap_sort;

	heap_sort = createMinHeap();
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		if (graph->pVertex[i] == TRUE) {
			for (int j = 0; j < graph->maxVertexCount; j++) {
				if (graph->ppAdjEdge[i][j]) {
					infoList[i][0] = graph->ppAdjEdge[i][j];
					infoList[i][1] = i;
					infoList[i][2] = j;
					// break;
					element ele;
					ele.data = infoList[i][0];
					insertHeap(heap_sort, ele);
				}
			}
		}
	}
	for (int i = 1 ; i <= heap_sort->currentSize ; i++)
        printf("%d ", heap_sort->heap[i].data);
	// for (int i = 0; i < MAX; i++) {
	// 	printf("{%d %d %d}\n", infoList[i][0], infoList[i][1], infoList[i][2]);
	// }

	deleteArrayGraph(graph);
	// system("leaks a.out");
	return (0);
}