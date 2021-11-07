#include "adjacencyMatrix.h"

// typedef struct ArrayGraphType
// {
// 	int maxVertexCount;		// 최대 노드 개수
// 	int currentVertexCount;	// 현재 사용되는 노드의 개수
// 	int graphType;			// 그래프 종류: 1-Undirected, 2-Directed
// 	int **ppAdjEdge;		// 간선 저장을 위한 2차원 array
// 	int *pVertex;			// 노드 저장을 위한 1차원 array
// } ArrayGraph;

// 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount)
{
	//ppAdjEdge, pVertex, maxVertexCount, graphType
    //currentVertexCount
    ArrayGraph *graph;

    graph = malloc(sizeof(ArrayGraph));
	memset(graph, 0, sizeof(ArrayGraph));

	graph->graphType = GRAPH_UNDIRECTED;
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;

    graph->ppAdjEdge = malloc(sizeof(int *) * maxVertexCount);
	memset(graph->ppAdjEdge,0,maxVertexCount * sizeof(int *));

	for (int i = 0; i < maxVertexCount; i++)
	{
		graph->ppAdjEdge[i] = malloc(sizeof(int) * maxVertexCount);
		memset(graph->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
	}
    graph->pVertex = malloc(sizeof(int) * maxVertexCount);
	memset(graph->pVertex, 0, sizeof(int) * maxVertexCount);
	return (graph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	//ppAdjEdge, pVertex, maxVertexCount, graphType
    // currentVertexCount

    ArrayGraph *g;
    g = createArrayGraph(maxVertexCount);
    g->graphType = GRAPH_DIRECTED;
    return (g);
}

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph)
{
	//ppAdjEdge, pVertex
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph)
{
    return (pGraph->currentVertexCount == 0);
}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	//pVertex, currentVertexCount
	if (pGraph->pVertex[vertexID] == TRUE)
		return (-1);
	pGraph->pVertex[vertexID] = TRUE;
	pGraph->currentVertexCount++;
	return (vertexID);
}

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
 //directed vs undirected 분기(graphType)
    // pVertex, ppAdjEdge
    if (!isVertexRangeCorrect(pGraph, fromVertexID) || !isVertexRangeCorrect(pGraph, toVertexID))
        return (0);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (0);
        
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
    return (1);   
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
 //directed vs undirected 분기(graphType)
    // pVertex, ppAdjEdge
    if (!isVertexRangeCorrect(pGraph, fromVertexID) || !isVertexRangeCorrect(pGraph, toVertexID))
        return (0);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (0);
        
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    return (1);   
}

// 노드의 유효성 점검.
int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
    if (!isVertexRangeCorrect(pGraph, vertexID))
        return (0);
	return (pGraph->pVertex[vertexID]);
}

int isVertexRangeCorrect(ArrayGraph *pGraph, int vertexID)
{
    return (0 <= vertexID && vertexID <= pGraph->maxVertexCount - 1);   
}

//vertex 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
    int i, j;
    // pVertex, ppAdjEdge
    if (!isVertexRangeCorrect(pGraph, vertexID) || !checkVertexValid(pGraph, vertexID))
        return (-1);
        
    pGraph->pVertex[vertexID] = 0;
    pGraph->currentVertexCount--;
    
    i = 0, j = 0;
    for (i = 0; i < pGraph->maxVertexCount; i++)
        pGraph->ppAdjEdge[vertexID][i] = 0;
    for (i = 0; i < pGraph->maxVertexCount; i++)
        pGraph->ppAdjEdge[i][vertexID] = 0;    
    return (vertexID);   
}

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	//directed vs undirected 분기
	//ppAdjEdge
	if (!isVertexRangeCorrect(pGraph, fromVertexID) || !isVertexRangeCorrect(pGraph, toVertexID))
        return (-1);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (-1);
	 if (pGraph->graphType == GRAPH_DIRECTED)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	}
	else
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	}
	return (fromVertexID);
}

// 그래프 정보(ppAdjEdge) 출력
void displayArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount ;i++)
	{
		int is = pGraph->pVertex[i];
		if (is)
			printf("\033[33m[%d]: has_vertex\n\033[37m", i);
		else
			printf("\033[34m[%d]: no_vertex\n\033[37m", i);
		
	}
    printf("    ");
    for (int i = 0; i < pGraph->maxVertexCount; i++)
        printf("\033[32m%d\033[37m ", i);
    printf("\n");
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        printf("\033[32m%d\t\033[37m", i);
        for (int j = 0; j < pGraph->maxVertexCount; j++)
            printf("%d ", pGraph->ppAdjEdge[i][j]);
        printf("\033[32m\n\033[37m");
    }
}

// #define USED				1
// #define NOT_USED			0

// #define SUCCESS				1
// #define FAIL				0

// #define TRUE				1
// #define FALSE				0

// #define GRAPH_UNDIRECTED	1
// #define GRAPH_DIRECTED		2
