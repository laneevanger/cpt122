#include "display.h"

void displaySong(Node* list)
{
	Node* headptr = list;
	char thisArtist[LITERALLYMAGICNUMBER] = 0;
	//150 items at 50 long, good enough for me
	char allArtists[LITERALLYMAGICNUMBER][SMALLERMAGIC] = { 0 };
	int aLength = 0;
	int aMenu = 0;
	int found = 0;
	int choice = 0;

	do
	{
		system("cls");
		printf("Would you like to:\n");
		printf("1. Print all records\n");
		printf("2. Print an artists records\n\n");
		scanf("%d", &choice);

	} while (isMenuInput(choice, 1, 2) != 1);

	if (choice == 2)
	{

		//will never hit magic break case
		while (list != NULL && aLength < LITERALLYMAGICNUMBER)
		{
			found = 0;
			for (int i = 0; i < aLength; i++)
			{
				if (strcmp(list->userPlaylist.artist, allArtists[i]) == 0)
				{
					found = 1;
				}
			}
			if (found = 0)
			{
				strcpy(allArtists[aLength], list->userPlaylist.artist);
			}
			list = list->pNext;
			aLength++;
		}

		system("cls");
		for (int i = 0; i < aLength; i++)
		{
			printf("%d. %s\n", i + 1, list[i]);
		}
		do
		{
			scanf("\nChoice: %d", &aMenu);
		} while (isMenuInput(aMenu, 0, aLength - 1) != 1);


	}

	while (list != NULL)
	{
		if (choice == 1 || strcmp(headptr->userPlaylist.artist, thisArtist))
		{
			printf("%s,%s", headptr->userPlaylist.artist, headptr->userPlaylist.albumTitle);
			printf("%s,%s", headptr->userPlaylist.songTitle, headptr->userPlaylist.genre);
			printf("%d:%d,", headptr->userPlaylist.songLength.minutes, headptr->userPlaylist.songLength.seconds);
			printf("%d,%d", headptr->userPlaylist.plays, headptr->userPlaylist.rating);
		}
		headptr = &((*headptr).pNext);
	}
}