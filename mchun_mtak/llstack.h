#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

typedef ListNode StackNode;
typedef struct LinkedStackType
{
	int	maxElementCount;
	int currentElementCount;	// 현재 원소의 개수
	LinkedList* pTopElement;		// Top 노드의 포인터
} LinkedStack;

LinkedStack* createLinkedStack(int max);

int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
int isBracketMatch(char *pSource);
