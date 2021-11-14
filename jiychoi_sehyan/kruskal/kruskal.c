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
	//heap에 간선과 weight 넣기
	//sort
	//weight가 작은 간선부터 트리에 넣기
	//사이클이 생기는 간선은 넣지 않기
	//다 넣으면 끝
	deleteArrayGraph(graph);
	return (0);
}