int distance[10];
int S[10];

int nextVertex(ArrayGraph* pGraph, int n)
{
  int min = INT_MAX;
  int minPos = -1;
  for(int i = 0; i <n; i++)
    {
     if((distance[i] < min) && !S[i])
     {
       min = distance[i];
       minPos = i;
     }
    }
  return minPos;
}

int printStep(int step)
{
  printf("\n%d: S= {",step);
  for (int i=0; i<6; i++)
    if(S[i] == TRUE)
      printf("%d", i);
  printf("}\t \t");
  printf("distance: [");
  for (int i=0; i< 5; i++)
    if(distance[i] == INF)
      printf(" * ");
    else
      printf(" %d ",distance[i]);
  printf("]");
  return ++step;
}

void Dijkstra(ArrayGraph *pGraph, int startVertex)
{
  int n = pGraph->currentVertexCount;
  for(int i=1; i<n; i++)
    {
      distance[i] = pGraph->ppAdjEdge[startVertex][i];
      S[i] =FALSE;
    }

  S[startVertex] = TRUE;
  distance[startVertex] = 0;

  int step = printStep(0);
  for (int i = 0; i < n-1; i++)
    {
      int u = nextVertex(pGraph,n);
      S[u] = TRUE;
      for(int w =0; w<n; w++)
        if(!S[w])
          if(distance[u] + pGraph->ppAdjEdge[u][w] < distance[w])
            distance[w] = distance[u] + pGraph->ppAdjEdge[u][w];

      step = printStep(step);
    }
  }
