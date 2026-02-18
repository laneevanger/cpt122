#include "record.h"

typedef struct node
{
	struct Node* pNext;
	struct Node* pLast;
	Record userPlaylist;
}Node;

Node* makeNode(Record playlist);