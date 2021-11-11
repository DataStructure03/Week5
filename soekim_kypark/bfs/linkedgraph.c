
#include "ArrayStack.h"
#include "linkedgraph.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
LinkedGraph* createLinkedGraph(int maxVertexCount)
{
    LinkedGraph *pGraph = NULL;
    if(maxVertexCount <= 0)
       return (NULL);
    if (!(pGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph))))
        return (NULL);
    pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->currentEdgeCount = 0;
	pGraph->graphType = GRAPH_UNDIRECTED;
  pGraph->visited = malloc (sizeof(int)*pGraph->maxVertexCount);
    if(!(pGraph->ppAdjEdge = malloc(sizeof(LinkedList*)*maxVertexCount)))
    {
        free(pGraph);
        return (NULL);
    }
    if(!(pGraph->pVertex = malloc(sizeof(int)*maxVertexCount)))
    {
        free(pGraph->ppAdjEdge);
        free(pGraph);
        return (NULL);
    }
    memset(pGraph->pVertex, 0, sizeof(int)*maxVertexCount);
    for(int i =0; i < maxVertexCount; i++)
        {
            pGraph->ppAdjEdge[i] = malloc(sizeof(LinkedList)*maxVertexCount);
            createLinkedList(pGraph->ppAdjEdge[i]);
        }
    return (pGraph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
    LinkedGraph *pGraph =  createLinkedGraph(maxVertexCount);
    pGraph->graphType = GRAPH_DIRECTED;

    return (pGraph);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
    if (pGraph)
    {
        if(pGraph->pVertex)
            free(pGraph->pVertex);
        for (int i =0; i<pGraph->maxVertexCount; i++)
            if(pGraph->ppAdjEdge)
                free(pGraph->ppAdjEdge[i]);
        if(pGraph->ppAdjEdge)
            free(pGraph->ppAdjEdge);
    free(pGraph);
    }
}

int isEmptyLG(LinkedGraph* pGraph)
{
    if(pGraph->currentVertexCount == 0)
        return (TRUE);
    return (FALSE);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
    if (!pGraph)
        return (FALSE);
    if (pGraph->maxVertexCount < vertexID)
        return (FALSE);
    if (pGraph->pVertex[vertexID] == 1)
        return (FALSE);
    
    pGraph->pVertex[vertexID] = 1;
    pGraph->currentVertexCount++;
    pGraph->visited[vertexID] =0;
    return (TRUE);
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
    if (pGraph)
        if (pGraph->maxVertexCount > fromVertexID && pGraph->maxVertexCount > toVertexID)
        {
            ListNode node;
            node.data =toVertexID;
            addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, node);
            if (pGraph->graphType == GRAPH_UNDIRECTED)
            {
                node.data =fromVertexID;
                addLLElement(pGraph->ppAdjEdge[toVertexID], 0, node);
                pGraph->currentEdgeCount++;
            }
            pGraph->currentEdgeCount++;
            return (TRUE);
        }
    return (FALSE);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
  if (pGraph)
        if (pGraph->maxVertexCount > fromVertexID && pGraph->maxVertexCount > toVertexID)
        {
            ListNode node;
            node.data =toVertexID;
            node.weight = weight;
            addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, node);
            if (pGraph->graphType == GRAPH_UNDIRECTED)
            {
                node.data =fromVertexID;
                addLLElement(pGraph->ppAdjEdge[toVertexID], 0, node);
                pGraph->currentEdgeCount++;
            }
            pGraph->currentEdgeCount++;
            return (TRUE);
        }
    return (FALSE);
  
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
  while(pGraph->ppAdjEdge[vertexID]->currentElementCount)
    {
      deleteGraphNode(pGraph->ppAdjEdge[vertexID], 0);
    }
  pGraph->pVertex[vertexID] = 0;
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
  if (pGraph)
  {
    if(fromVertexID < pGraph->maxVertexCount && toVertexID < pGraph->maxVertexCount)
    {
      deleteGraphNode(pGraph->ppAdjEdge[fromVertexID],toVertexID);
      if (pGraph->graphType == GRAPH_UNDIRECTED)
      deleteGraphNode(pGraph->ppAdjEdge[toVertexID],fromVertexID);
     }
  }
}
void deleteGraphNode(LinkedList* pList, int delVertexID)
{
  int pos = findGraphNodePosition(pList, delVertexID);
  if (pos > -1)
    removeLLElement(pList, pos);
}

int findGraphNodePosition(LinkedList* pList, int vertexID)
{
  int i = -1;
  ListNode *node;
  node= pList->headerNode.pLink;
  if (vertexID >= 0)
    while(node != NULL)
    {
      i++;
      if (node->data == vertexID)
        return (i);
      node = node->pLink;
    }
  return (i);
}

int getEdgeCountLG(LinkedGraph* pGraph)
{
  return (pGraph->currentEdgeCount);
}

int getMaxVertexCountLG(LinkedGraph* pGraph)
{
   return (pGraph->maxVertexCount); 
}

int getGraphTypeLG(LinkedGraph* pGraph)
{
  return (pGraph->graphType);
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
  ListNode *node;
    for(int i =0; i < pGraph->maxVertexCount; i++)
        {
          node = pGraph->ppAdjEdge[i]->headerNode.pLink;
          if (pGraph->pVertex[i] == 1)
          { 
            printf("%d\t", i);
            while(node !=NULL)
              {
                printf ("%d ", node->data);
                node = node->pLink;
                }
            printf("\n");
            }
        }

}


