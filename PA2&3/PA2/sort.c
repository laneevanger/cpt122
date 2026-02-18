#include "sort.h"

void songSort(Node* playlist, int length)
{
	Node* headptr = playlist;
	//Node* last = playlist->pLast;
	Node* next = playlist->pNext;
	Node* cur = playlist;
	Record hold = {0};
	int choice = 0;
	do
	{
		printf("1. Sort based on artist (A-Z)\n");
		printf("2. Sort based on album title (A-Z)\n");
		printf("3. Sort based on rating (1-5)\n");
		printf("4. Sort based on times played (Most to Least)\n");
		printf("5. Cancel\n\n");
		scanf("%d", &choice);

	} while (isMenuInput(choice, 1, 5) != 1);

	switch (choice)
	{
	//artist
	case 1:
		for (int i = 0; i < length; i++)
		{
			cur = headptr;
			for (int k = 0; k < i; k++)
			{
				cur = cur->pNext;
				next = cur->pNext;
			}
			for (int k = i + 1; k < length - 1; k++)
			{
				if (strcmp(cur->userPlaylist.artist, next->userPlaylist.artist) < 0)
				{
					hold = cur->userPlaylist;
					cur->userPlaylist = next->userPlaylist;
					next->userPlaylist = hold;
				}
				next = next->pNext;
			}
		}
		break;
	//album title
	case 2:
		for (int i = 0; i < length; i++)
		{
			cur = headptr;
			for (int k = 0; k < i; k++)
			{
				cur = cur->pNext;
				next = cur->pNext;
			}
			for (int k = i + 1; k < length - 1; k++)
			{
				if (strcmp(cur->userPlaylist.albumTitle, next->userPlaylist.albumTitle) < 0)
				{
					hold = cur->userPlaylist;
					cur->userPlaylist = next->userPlaylist;
					next->userPlaylist = hold;
				}
				next = next->pNext;
			}
		}
		break;
	//rating
	case 3:
		for (int i = 0; i < length; i++)
		{
			cur = headptr;
			for (int k = 0; k < i; k++)
			{
				cur = cur->pNext;
				next = cur->pNext;
			}
			for (int k = i + 1; k < length - 1; k++)
			{
				if (cur->userPlaylist.rating < next->userPlaylist.rating)
				{
					hold = cur->userPlaylist;
					cur->userPlaylist = next->userPlaylist;
					next->userPlaylist = hold;
				}
				next = next->pNext;
			}
		}
		break;
	//plays
	case 4:
		for (int i = 0; i < length; i++)
		{
			cur = headptr;
			for (int k = 0; k < i; k++)
			{
				cur = cur->pNext;
				next = cur->pNext;
			}
			for (int k = i + 1; k < length - 1; k++)
			{
				if (cur->userPlaylist.plays < next->userPlaylist.plays)
				{
					hold = cur->userPlaylist;
					cur->userPlaylist = next->userPlaylist;
					next->userPlaylist = hold;
				}
				next = next->pNext;
			}
		}
		break;
	//cancel
	case 5:
		break;

	}

}