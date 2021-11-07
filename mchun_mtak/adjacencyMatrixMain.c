 #include "adjacencyMatrix.h"

int main()
{
	ArrayGraph *g = createArrayGraph(5);

	for (int i = 0; i < 5; i++)
	{
		addVertexAG(g, i);
		if (i % 2)
			addEdgeAG(g, i, i - 1);
	}
    displayArrayGraph(g);
    printf("\n\n");
    
	for (int i = 0; i < 5; i+=4)
		removeVertexAG(g, i);
	for (int i = 0; i < 5; i+=3)
		removeEdgeAG(g, i, i + 1);
    displayArrayGraph(g);

	g = createArrayGraph(15);
	for (int i = 0; i < 10; i++)
		addVertexAG(g, i);
	for (int i = 0; i < 10; i++)
        addEdgeAG(g, i, i+ 1);
    displayArrayGraph(g);

	printf("\033[34mDFS_Matrix\033[37m\n");
	DFS(g);
	printf("\033[34mBFS_Matrix\033[37m\n");
	BFS(g);
    return (0);
}