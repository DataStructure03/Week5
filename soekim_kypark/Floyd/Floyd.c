int A[6][6];
void printFloyd(ArrayGraph* pGraph, int step)
{
  int n= pGraph->currentVertexCount;
  printf("%d :",step);
  for(int i =0; i<n; i++)
    {
      printf("\t\t");
      for(int j=0; j<n; j++){
        if(A[i][j] == INF)
          printf(" * ");
        else
          printf(" %d ",A[i][j]);
      }
      printf("\n");
    }
}

void Floyd(ArrayGraph *pGraph, int n)
{
  for(int v =0; v<n; v++)
    for(int w =0; w <n; w++)
        A[v][w] = pGraph->ppAdjEdge[v][w];

  int step = -1;
  printFloyd(pGraph,step);
  for(int k = 0; k <n; k++)
    {
      for(int v = 0; v < n; v++)
        for(int w=0; w < n; w++)
          if(A[v][k] + A[k][w] < A[v][w])
            A[v][w] = A[v][k] + A[k][w];
      printFloyd(pGraph,++step);
    }
}
