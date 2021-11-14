#include "./heap.h"
#define ROOT 1
// typedef struct elementType {
// 	int data;
// } element;

// enum HeapType {
// 	MaxHeap,MinHeap
// };

// typedef struct arrayHeap {
// 	element heap[MAX_ELEMENT];
// 	int currentSize;
// 	HeapType heaptype;
// } arrHeap;

arrHeap *createMaxHeap()
{
	arrHeap *maxHeap;

	maxHeap = (arrHeap *)calloc(1, sizeof(arrHeap));
	maxHeap->heaptype = MaxHeap;
	maxHeap->currentSize = 0;
	return (maxHeap);
}

arrHeap *createMinHeap()
{
	arrHeap *minHeap;
	
	minHeap = (arrHeap *)calloc(1, sizeof(arrHeap));
	minHeap->heaptype = MinHeap;
	minHeap->currentSize = 0;
	return (minHeap);
}

void deleteHeap(arrHeap *heap)
{
	free(heap);
}

int insertHeap(arrHeap *heap, element ele)
{
	int i;
	heap->heap[heap->currentSize + 1] = ele;
	i = heap->currentSize + 1;
	if (heap->heaptype == MaxHeap)
	{
		while ((i != 1) && heap->heap[i / 2].data < heap->heap[i].data)
		{
			int tmp;
			tmp = heap->heap[i / 2].data;
			heap->heap[i / 2].data = heap->heap[i].data;
			heap->heap[i].data = tmp;
			i = i/2;
		}
	} else {
		while ((i != 1) && heap->heap[i / 2].data > heap->heap[i].data)
		{
			int tmp;
			tmp = heap->heap[i / 2].data;
			heap->heap[i / 2].data = heap->heap[i].data;
			heap->heap[i].data = tmp;
			i = i/2;
		}
	}
	heap->currentSize++;
	return heap->heap[i].data;
}

element removeRoot(arrHeap *heap)
{
    element item;
    element tmp;
    int     currentSize;
    int     largest;
    int     small;

    item = heap->heap[ROOT];
    heap->heap[ROOT] = heap->heap[heap->currentSize--];
    currentSize = 2;
    if (heap->heaptype == MaxHeap)
    {
       while (currentSize <= heap->currentSize)
       {
            if (currentSize < heap->currentSize && heap->heap[currentSize + 1].data > heap->heap[currentSize].data)
                largest = currentSize + 1;
            else
                largest = currentSize;
            if (heap->heap[largest / 2].data > heap->heap[largest].data)
                break;
            tmp = heap->heap[largest / 2];
            heap->heap[largest / 2] = heap->heap[largest];
            heap->heap[largest] = tmp;
            currentSize = largest * 2;
       }
    }
    else
    {
       while (currentSize <= heap->currentSize)
       {
            if (currentSize < heap->currentSize && heap->heap[currentSize + 1].data < heap->heap[currentSize].data)
                small = currentSize + 1;
            else
                small = currentSize;
            if (heap->heap[small / 2].data < heap->heap[small].data)
                break;
            tmp = heap->heap[small / 2];
            heap->heap[small / 2] = heap->heap[small];
            heap->heap[small] = tmp;
            currentSize = small * 2;
       }
    }
   return item; 
}

