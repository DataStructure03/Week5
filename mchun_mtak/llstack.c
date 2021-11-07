#include "llstack.h"
#include <stdio.h>
LinkedStack* createLinkedStack(int max)
{
	LinkedStack *stack;

	stack = malloc(sizeof(LinkedStack));
	stack->maxElementCount = max;
	stack->currentElementCount = 0;
	stack->pTopElement = createLinkedList();
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	if (!pStack)
		return -1;
	if (isLinkedStackFull(pStack))
		return -1;
	ListNode *node = malloc(sizeof(ListNode));
	node->data = element.data;
	addLLElement(pStack->pTopElement, 0, element);
	pStack->currentElementCount++;
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *copy;
	StackNode *src;

	if (!pStack)
		return NULL;
	if (isLinkedStackEmpty(pStack))
		return NULL;
	pStack->currentElementCount--;
	src = getLLElement(pStack->pTopElement, 0);
	copy = malloc(sizeof(StackNode));
	copy->data = src->data;
	removeLLElement(pStack->pTopElement, 0);
	return (copy);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (!pStack)
		return NULL;
	if (isLinkedStackEmpty(pStack))
		return NULL;
	return (getLLElement(pStack->pTopElement, 0));
}

void deleteLinkedStack(LinkedStack* pStack)
{
	deleteLinkedList(pStack->pTopElement);
	free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	return (pStack->currentElementCount == 0);
}

int isBracketMatch(char *pSource)
{
	LinkedStack *LS;
	ListNode element;
	ListNode *ptr;
	ListNode *curr;

	if (!pSource)
		return -1;
	LS = createLinkedStack(strlen(pSource));
	for (int i = 0; pSource[i]; i++)
	{
		if (pSource[i] == '(')
			pushLS(LS, element);
		else if (pSource[i] == ')')
		{
			if (!(ptr = popLS(LS)))
			{
				deleteLinkedStack(LS);
				return 0;
			}
			else
				free(ptr);
		}
	}
	if (!isLinkedStackEmpty(LS))
		return 0;
	else
		return 1;
}
