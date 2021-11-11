#include "linkedlist.h"
// create LinkedList
LinkedList* createLinkedList(void){
	LinkedList* L;
	L = (LinkedList*)malloc(sizeof(LinkedList));
	if(L != NULL)
		memset(L,0, sizeof(LinkedList));
	else
		return NULL;
	return L;
}
// add element to LinkedList
int addLLElement(LinkedList* pList, int position, ListNode element){
	int i = -1;
	ListNode* preNode;
	ListNode* newNode;
	if (pList){
		if (0<= position && position <= pList->currentElementCount){
			newNode = (ListNode*)malloc(sizeof(ListNode));
			if(newNode){
				preNode = getLLElement(pList, position-1);
				*newNode = element;
				newNode->pLink = preNode->pLink;
				preNode->pLink = newNode; 
				pList->currentElementCount++;
				return TRUE;
			}
		}
	}
    return FALSE;
}
// remove element from LinkedList
int removeLLElement(LinkedList* pList, int position){
	ListNode* preNode;
	ListNode* tmp;
	if(pList){
		if(0<=position && position <=pList->currentElementCount){
			preNode = getLLElement(pList, position - 1);
			tmp = preNode->pLink;
			preNode->pLink = tmp->pLink;
			free(tmp);
			pList->currentElementCount--;
			return TRUE;
		}
	}
	return FALSE;
}
// search data from position that i want to get
ListNode* getLLElement(LinkedList* pList, int position){
    int i = -1;
	ListNode* Node;
    if(pList){
		Node = &(pList->headerNode);
		while(++i <= position)
			Node = Node->pLink;
		return Node;
    }
    else 
		return NULL;
}
// clear LinkedList
void clearLinkedList(LinkedList* pList){
    int i = -1;
	ListNode* Node;
	if (pList){
		Node = (ListNode*)malloc(sizeof(ListNode)); 
		Node = &(pList->headerNode);
		while(++i < pList->currentElementCount){
			Node = Node->pLink;
			Node->data = 0;
		}
	}
}
// get arraylist's length
int getLinkedListLength(LinkedList* pList){
	if (pList)
		return(pList->currentElementCount);
	else
		return FALSE;
}
// delete LinkedList
void deleteLinkedList(LinkedList* pList){
    int i = -1;
	ListNode* Node;
	if (pList){
		Node = &(pList->headerNode);
		while(++i < pList->currentElementCount){
			Node = Node->pLink;
			free(Node);
		}
		Node = NULL;
		free(pList);
	}
}
