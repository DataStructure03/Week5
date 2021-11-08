#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

void printStack(LinkedStack *pStack)
{
	StackNode *tmp;

	tmp = pStack->pTopElement;
	printf("TOP >");
	while (tmp)
	{
		printf(" [%d] > ", tmp->data);
		tmp = tmp->pLink;
	}
	printf("END\n");
}

void printNode(StackNode *node)
{
	printf("{%d}\n", node->data);
}

int main()
{
	LinkedStack *pStack;
	StackNode node;

	pStack = createLinkedStack();
	node.data = 10;
	pushLS(pStack, node);
	node.data = 11;
	pushLS(pStack, node);
	node.data = 12;
	pushLS(pStack, node);
	printStack(pStack);
	printNode(peekLS(pStack));

	StackNode *tmp;
	tmp = popLS(pStack);
	printNode(tmp);
	free(tmp);

	printStack(pStack);

	deleteLinkedStack(pStack);
	return 0;
}