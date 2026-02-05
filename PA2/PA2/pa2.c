#include "pa2.h"

void printMenu(void)
{
	printf("1. Load\n");
	printf("2. Store\n");
	printf("3. Display\n");
	printf("4. Insert\n");
	printf("5. Delete\n");
	printf("6. Edit\n");
	printf("7. Sort\n");
	printf("8. Rate\n");
	printf("9. Play\n");
	printf("10. Shuffle\n");
	printf("11. Exit\n\n");
}

int isMenuInput(int choice)
{
	if (choice >= LOAD && choice <= EXIT)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

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

void loadPlaylist(FILE* file, Node** playlist)
{
	char line[150];
	fgets(line, sizeof(line), file);


}

void storePlaylist(Node playlist, FILE* file)
{

}

void editSong(Node* playlist)
{

}

//doesnt find song 
int rateSong(Node* playlist)
{
	char song[40];
	int rating = 0;

	printf("What song would you like to rate:\n");
	scanf(" %s", &song);
	printf("What would you like to rate the song:\n");
	scanf(" %d", &rating);

	if (rating < 1)
	{
		return 1;
	}
	else if (rating > 5)
	{
		return 5;
	}
	else
	{
		return rating;
	}
}