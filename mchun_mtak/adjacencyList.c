#include "adjacencyList.h"

// 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	//maxVertexCount, currentEdgeCount, currentVertexCount, graphType, ppAdjEdge, pVertex
	LinkedGraph *graph;
    
    graph = malloc(sizeof(LinkedGraph));
	memset(graph, 0, sizeof(LinkedGraph));
    
	graph->currentEdgeCount = 0;
	graph->currentVertexCount = 0;
	graph->maxVertexCount = maxVertexCount;
	graph->graphType = GRAPH_UNDIRECTED;

    graph->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
    for (int i = 0; i < maxVertexCount; i++)
        graph->ppAdjEdge[i] = createLinkedList();
	graph->pVertex = malloc(sizeof(int) * maxVertexCount);
	memset(graph->pVertex, 0, sizeof(int) * maxVertexCount);
	return graph;
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
    LinkedGraph *g;
    g = createLinkedGraph(maxVertexCount);
    g->graphType = GRAPH_DIRECTED;
    return (g);
}

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph)
{
    int     i;

    for (i = 0; i < pGraph->maxVertexCount; i++)
    {
        deleteLinkedList(pGraph->ppAdjEdge[i]);
    }
    free(pGraph->pVertex);
    free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph)
{
    return (pGraph->currentVertexCount == 0);
}

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
    if (!isVertexRangeCorrect(pGraph, vertexID))
        return (0);
    pGraph->pVertex[vertexID] = TRUE;
}

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
    if (!isVertexRangeCorrect(pGraph, fromVertexID) || !isVertexRangeCorrect(pGraph, toVertexID))
        return (-1);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (-1);

    LinkedList *fromVertexList = pGraph->ppAdjEdge[fromVertexID];
    LinkedList *toVertexList = pGraph->ppAdjEdge[toVertexID];
    ListNode toNode;

    if (getLLElement(fromVertexList, toVertexID) != NULL)
        return (-1);
    toNode.toVertexID = toVertexID;
    toNode.data = 1;
    addLLElement(fromVertexList, 0, toNode);
	pGraph->currentEdgeCount++;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
    {
        toNode.toVertexID = fromVertexID;
        addLLElement(toVertexList, 0, toNode);
		pGraph->currentEdgeCount++;
    }
	return (1);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
    if (!isVertexRangeCorrect(pGraph, fromVertexID) || !isVertexRangeCorrect(pGraph, toVertexID))
        return (-1);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (-1);

    LinkedList *fromVertexList = pGraph->ppAdjEdge[fromVertexID];
    LinkedList *toVertexList = pGraph->ppAdjEdge[toVertexID];
    ListNode toNode;

    if (getLLElement(fromVertexList, toVertexID) != NULL)
        return (-1);
    toNode.toVertexID = toVertexID;
    toNode.data = weight;
    addLLElement(fromVertexList, 0, toNode);
	pGraph->currentEdgeCount++;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
    {
        toNode.toVertexID = fromVertexID;
        addLLElement(toVertexList, 0, toNode);
	    pGraph->currentEdgeCount++;
    }
	return (1);
}

// 노드의 유효성 점검.
int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
    if (!isVertexRangeCorrect(pGraph, vertexID))
        return (0);
    return (pGraph->pVertex[vertexID]);
}

int    isVertexRangeCorrect(LinkedGraph *pGraph, int vertexID)
{
    return (0 <= vertexID && vertexID <= pGraph->maxVertexCount - 1);
}


// 노드 제거 - 무방향그래프일때는 해당. 방향그래프일때는..?
int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	LinkedList *vertexList = pGraph->ppAdjEdge[vertexID];
	ListNode *cur;
    int     is_success = 0;
    
	pGraph->currentVertexCount--;
	for (cur = &(vertexList->headerNode); cur != NULL; cur = cur->pLink)
	{
		LinkedList *target = pGraph->ppAdjEdge[cur->toVertexID];
		is_success += deleteGraphNode(target, vertexID);
        pGraph->currentEdgeCount--;
	}
	clearLinkedList(vertexList);
	pGraph->currentEdgeCount -= is_success;
    pGraph->pVertex[vertexID] = FALSE;
	return (1);
}

int deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int pos = 0;
	for (ListNode *cur = &(pList->headerNode); cur != NULL; cur = cur->pLink)
		{
			if (cur->toVertexID == delVertexID)
			{
				removeLLElement(pList, pos);
				return (1);
			}
			pos++;
		}
    return (0);
}


// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
    ListNode *cur;
	LinkedList *target = pGraph->ppAdjEdge[fromVertexID];
    LinkedList *toVertexTarget = pGraph->ppAdjEdge[toVertexID];
	int pos = 0;
    int toVertexPos = 0;

	for (cur = &(target->headerNode); cur != NULL; cur = cur->pLink)
	{
		if (cur->toVertexID == toVertexID)
    		removeLLElement(target, pos);
		pGraph->currentEdgeCount--;
        if (pGraph->graphType == GRAPH_UNDIRECTED)
        {
            toVertexPos = 0;
			for (cur = &(toVertexTarget->headerNode); cur != NULL; cur = cur->pLink)
            {
                if (cur->toVertexID == fromVertexID)
                    removeLLElement(toVertexTarget, toVertexPos);
                pGraph->currentEdgeCount--;
				toVertexPos++;
            }
	    }
		pos++;
	}
}

// 간선 개수 반환
int getEdgeCountLG(LinkedGraph* pGraph)
{
    return (pGraph->currentEdgeCount);
}


// 노드 개수 반환
int getVertexCountLG(LinkedGraph* pGraph)
{
    return (pGraph->currentVertexCount);
}

// 최대 노드 개수 반환
int getMaxVertexCountLG(LinkedGraph* pGraph)
{
    return (pGraph->maxVertexCount);
}
// 그래프 종류 반환.
int getGraphTypeLG(LinkedGraph* pGraph)
{
    return (pGraph->graphType);
}
// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph)
{   
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        printf("Vertex %d : ", i);
        for (ListNode *cur = pGraph->ppAdjEdge[i]->headerNode.pLink; cur != NULL; cur = cur->pLink)
			printf("\033[35m toVertexId: %d\033[32m weight : %d \033[37m\n", cur->toVertexID, cur->data);
        printf("\n");
    }
}