#include "heap.h"
#include <stdio.h>
int main()
{
    arrHeap *heap = createMaxHeap();
    element data;
    for (int i = 1 ; i < 15 ; i++)
    {
        data.data = i;
        insertHeap(heap, data);
    }
	printf(">>>%d\n", heap->currentSize);
    for (int i = 1 ; i <= heap->currentSize ; i++)
        printf("%d ", heap->heap[i].data);
    return 0;
}
