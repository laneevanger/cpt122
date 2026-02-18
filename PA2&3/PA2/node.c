#include "node.h"

Node* makeNode(Record playlist)
{
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew != NULL)
	{
		pNew->userPlaylist = playlist;
		pNew->pNext = NULL;
		pNew->pLast = NULL;
	}
	return pNew;
}