#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// LinkedList's Node
typedef struct ListNodeType
{
	int data;//node's data
  int weight;
	struct ListNodeType* pLink;//next node
} ListNode, *pListNode;
// LinkedList
typedef struct LinkedListType
{
	int currentElementCount;	// Element's current index
	ListNode headerNode;		// Header Node
} LinkedList;

// create LinkedList
LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
// remove element from LinkedList
int removeLLElement(LinkedList* pList, int position);
// search data from position that i want to get
ListNode* getLLElement(LinkedList* pList, int position);
// clear LinkedList
void clearLinkedList(LinkedList* pList);
// get arraylist's length
int getLinkedListLength(LinkedList* pList);
// delete LinkedList
void deleteLinkedList(LinkedList* pList);
#endif
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_
#define TRUE		1
#define FALSE		0
#endif
