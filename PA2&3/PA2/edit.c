#include "edit.h"

//rating and artist unfinished
//not to specification, better than specification
void editSong(Node* playlist)
{
	char thisArtist[LITERALLYMAGICNUMBER] = { 0 };
	char thisSong[LITERALLYMAGICNUMBER] = { 0 };
	Node* last = { 0 };
	Node* next = { 0 };
	int choice = 0;

	findSong(playlist, thisArtist, thisSong);

	if (thisArtist != NULL && thisSong != NULL)
	{
		while (strcmp(playlist->userPlaylist.artist, thisArtist) != 0 && strcmp(playlist->userPlaylist.songTitle, thisSong) != 0)
		{
			playlist = playlist->pNext;
		}
	}

	do
	{
		system("cls");
		printf("1. Artist\n");
		printf("2. Album title\n");
		printf("3. Song title\n");
		printf("4. Genre\n");
		printf("5. Song length\n");
		printf("6. Plays\n");
		printf("7. Rating\n");
		printf("8. Exit\n");
		printf("\n");
		scanf("%d", &choice);
	} while (isMenuInput(choice, 1, 8));

	if (choice < 8)
	{
		system("cls");
		switch (choice)
		{
		case 1:
			do
			{
				system("cls");
				scanf("New Artist (no , or \"): %s", playlist->userPlaylist.artist);
			} while (strchr(playlist->userPlaylist.artist, "\"") != NULL && strchr(playlist->userPlaylist.artist, ",") != NULL);
			break;
		case 2:
			scanf("New Album title: %s", playlist->userPlaylist.albumTitle);
			break;
		case 3:
			scanf("New Song title: %s", playlist->userPlaylist.songTitle);
			break;
		case 4:
			scanf("New Genre: %s", playlist->userPlaylist.genre);
			break;
		case 5:
			scanf("New Minutes: %d", playlist->userPlaylist.songLength.minutes);
			scanf("New Seconds: %d", playlist->userPlaylist.songLength.seconds);
			break;
		case 6:
			scanf("New Number of plays: %d", playlist->userPlaylist.plays);
			break;
		case 7:
			scanf("New Rating: %d", playlist->userPlaylist.rating);
			break;
		case 8:
			break;
		}
	}

}