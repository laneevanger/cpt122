#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
	struct Node* pNext;
}Node;

int makeNode(Node* list)
{
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew != NULL)
	{
		pNew->pNext = NULL;
	}
	else
	{
		return 0;
	}

	return pNew;
}

int fastnslow(Node* list)
{
	Node* slow = list;
	Node* fast = list;
	int loop = 0;

	while (slow != NULL && fast != NULL && loop != 1)
	{
		if (fast == slow)
		{
			loop = 1;
		}
		slow = slow->pNext;
		fast = fast->pNext;
		fast = fast->pNext;
	}
	return loop;
}

int main(void)
{
	Node* list = { 0 };
	makeNode(list);
	Node* cur = makeNode(list);

	cur->pNext = list;

	int answer = fastnslow(list);

	printf("%d", answer);
}
