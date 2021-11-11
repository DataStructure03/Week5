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
  LinkedStack *S = createLinkedStack();
  StackNode V;
  ListNode *node;

  pGraph->visited[vertexID] = 1;
  V.data = vertexID;

  pushLS(S,V);
  while(!isLinkedStackEmpty(S))
    {
      StackNode* U= popLS(S);
      vertexID = U->data;
      pGraph->visited[vertexID] = 1;
      printf(" %d ",vertexID);
      for (int i = pGraph->ppAdjEdge[vertexID]->currentElementCount; i >= 1; i--)
        {
          node = getLLElement(pGraph->ppAdjEdge[vertexID],i-1);
          V.data=node->data;
          if(node->data >= 0 && pGraph->visited[node->data] ==0)
          {
            pushLS(S,V);
            pGraph->visited[node->data] = 1;
          }
        }
    }
}
