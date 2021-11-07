 #include "adjacencyList.h"

int main()
{
	LinkedGraph *g = createLinkedGraph(5);

	
	for (int i = 0; i < 5; i++)
	{
		addVertexLG(g, i);
		if (i % 2)
			addEdgeLG(g, i, i - 1);
	}
    displayLinkedGraph(g);
    printf("\n\n");
    
    return (0);

	for (int i = 0; i < 5; i+=4)
		removeVertexLG(g, i);
	for (int i = 0; i < 5; i+=3)
		removeEdgeLG(g, i, i + 1);
    displayLinkedGraph(g);

	g = createLinkedGraph(15);
	for (int i = 0; i < 10; i++)
		addVertexLG(g, i);
	for (int i = 0; i < 10; i++)
        addEdgeLG(g, i, i+ 1);
    displayLinkedGraph(g);
    return (0);
}