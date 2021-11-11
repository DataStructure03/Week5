#include "BFS.h"

#include <stdio.h>

int saveFirstNode(LinkedList *queue, LinkedGraph *g)
{
    int firstNode;
    for (firstNode= 0
        ; ! g->pVertex[firstNode] && firstNode < g->currentVertexCount
        ; ++firstNode);
    
    ListNode element;
    element.data = firstNode;
    return addLLElement(queue, queue->currentElementCount, element);
}

void bfsTraverse(LinkedGraph *g)
{
    LinkedList *nodes = createLinkedList();

    if (! saveFirstNode(nodes, g))
        return ;

    while (nodes->currentElementCount)
    {
        int currentNode = nodes->headerNode.pLink->data;
        removeLLElement(nodes, 0);
        if (g->visited[currentNode])
            continue;
        else
            g->visited[currentNode] = TRUE;
        printf("%d\n", currentNode);       
        
        for (pListNode adjacent = g->ppAdjEdge[currentNode]->headerNode.pLink
            ;adjacent
            ;adjacent = adjacent->pLink)
        {
            ListNode element;
            element.data = adjacent->data;
            addLLElement(nodes, nodes->currentElementCount, element); 
            // printf("enQueue %d \n", adjacent->data);
        }

        // printf("left %d\n", nodes->currentElementCount); //? "empty\n" : "umempty\n");
        // int a;
        // scanf("%d",&a);

    }

    memset(g->visited, 0, g->currentVertexCount * sizeof(int));
    return ;
}