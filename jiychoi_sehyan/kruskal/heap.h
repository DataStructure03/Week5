#ifndef HEAP_H
#define HEAP_H
#define MAX_ELEMENT 15

#include <stdlib.h>
#include <stdio.h>

typedef struct elementType {
	int data;
} element;

typedef enum _HeapType {
	MaxHeap,MinHeap
} HeapType;


typedef struct arrayHeap {
	element heap[MAX_ELEMENT];
	int currentSize;
	HeapType heaptype;
} arrHeap;


arrHeap *createMaxHeap();
arrHeap *createMinHeap();
void deleteHeap(arrHeap *heap);


int insertHeap(arrHeap *heap, element ele);
element removeRoot(arrHeap *heap);

#endif
