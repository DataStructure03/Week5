void traversal_DFS(LinkedGraph* pGraph, int vertexID)
{
  ListNode *node;
  pGraph->visited[vertexID] = 1;
  printf(" %d ",vertexID);
  node = pGraph->ppAdjEdge[vertexID]->headerNode.pLink;
  while(node != NULL)
    {
      if(node->data >= 0 && pGraph->visited[node->data] ==0)
        traversal_DFS(pGraph, node->data);
      node = node->pLink;
    }
}

void traversal_DFS2(LinkedGraph* pGraph, int vertexID)
{
  ArrayStack *S = createArrayStack(pGraph->maxVertexCount);
  StackNode V;
  ListNode *node;
  
  pGraph->visited[vertexID] = 1;
  V.data = vertexID;
  
  pushAS(S, V);
  while(!isArrayStackEmpty(S))
    {
      StackNode* U = popAS(S);
      vertexID = U->data;
      pGraph->visited[vertexID] =1;
      printf(" %d ",vertexID);
      for (int i = pGraph->ppAdjEdge[vertexID]->currentElementCount; i >= 1; i--)
        {
          node = getLLElement(pGraph->ppAdjEdge[vertexID],i-1);
          V.data=node->data;
          if(node->data >= 0 && pGraph->visited[node->data] ==0)
          {
            pushAS(S,V);
            pGraph->visited[node->data] =1;
          }
        }
    }
}
