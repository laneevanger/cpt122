#include "modify.h"

//assumes playlist is big enough, files pretty small so shouldnt be a problem
int loadSongs(FILE* file, Node** playlist)
{
	Record newRecord = { 0 };
	char line[LITERALLYMAGICNUMBER];
	char time[TIMEMAGIC];
	char firstName[LITERALLYMAGICNUMBER] = { 0 };
	char lastName[LITERALLYMAGICNUMBER] = { 0 };
	char* tok;
	int size = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		// kept comma in name
		if (strtok(line, "\"") == NULL)
		{
			tok = strtok(line, "\"");
			sscanf(tok, "%s, %s", &lastName, &firstName);
			strcat(firstName, " ");
			//150s big enough 100%
			strcat(firstName, lastName);
			strcpy(newRecord.artist, firstName);
		}
		//no comma in name
		else
		{
			tok = strtok(line, ",");
			strcpy(newRecord.artist, tok);

		}

		tok = strtok(NULL, ",");
		strcpy(newRecord.albumTitle, tok);

		tok = strtok(NULL, ",");
		strcpy(newRecord.songTitle, tok);

		tok = strtok(NULL, ",");
		strcpy(newRecord.genre, tok);

		tok = strtok(NULL, ",");
		sscanf(tok, "%d:%d", &newRecord.songLength.minutes, &newRecord.songLength.seconds);

		tok = strtok(NULL, ",");
		newRecord.plays = atoi(tok);

		tok = strtok(NULL, ",");
		newRecord.rating = atoi(tok);

		size++;

		Node* newNode = makeNode(newRecord);

		if (playlist != NULL)
		{
			(*playlist)->pLast = newNode;
			newNode->pNext = playlist;
			playlist = &((*playlist)->pLast);
		}
		else
		{
			playlist = &newNode;
		}

	}

	return size;
}

void storePlaylist(Node* playlist, FILE* file)
{
	if (playlist != NULL && file != NULL)
	{
		//first entry
		fprintf(file, "%s,%s", playlist->userPlaylist.artist, playlist->userPlaylist.albumTitle);
		fprintf(file, "%s,%s", playlist->userPlaylist.songTitle, playlist->userPlaylist.genre);
		fprintf(file, "%d:%d,", playlist->userPlaylist.songLength.minutes, playlist->userPlaylist.songLength.seconds);
		fprintf(file, "%d,%d", playlist->userPlaylist.plays, playlist->userPlaylist.rating);

		//all other entries
		while (playlist->pNext != NULL)
		{
			playlist = &((*playlist).pNext);
			fprintf(file, "%s,%s", playlist->userPlaylist.artist, playlist->userPlaylist.albumTitle);
			fprintf(file, "%s,%s", playlist->userPlaylist.songTitle, playlist->userPlaylist.genre);
			fprintf(file, "%d:%d,", playlist->userPlaylist.songLength.minutes, playlist->userPlaylist.songLength.seconds);
			fprintf(file, "%d,%d", playlist->userPlaylist.plays, playlist->userPlaylist.rating);
		}
	}
}

//same issue as edit
//garbage data can be entered atm
void insertSong(Node** playlist)
{
	Node* newNode = { 0 };

	system("cls");
	scanf("New Artist (no , or \"): %s", newNode->userPlaylist.artist);
	system("cls");
	scanf("New Album title: %s", newNode->userPlaylist.albumTitle);
	system("cls");
	scanf("New Song title: %s", newNode->userPlaylist.songTitle);
	system("cls");
	scanf("New Genre: %s", newNode->userPlaylist.genre);
	system("cls");
	scanf("New Minutes: %d", newNode->userPlaylist.songLength.minutes);
	system("cls");
	scanf("New Seconds: %d", newNode->userPlaylist.songLength.seconds);
	system("cls");
	scanf("New Number of plays: %d", newNode->userPlaylist.plays);
	system("cls");
	scanf("New Rating: %d", newNode->userPlaylist.rating);

	newNode->pNext = playlist;
	playlist = &newNode;
}

void deleteSong(Node** playlist)
{
	char thisArtist[LITERALLYMAGICNUMBER] = { 0 };
	char thisSong[LITERALLYMAGICNUMBER] = { 0 };
	Node* last = { 0 };
	Node* next = { 0 };

	findSong(playlist, thisArtist, thisSong);

	if (thisArtist != NULL && thisSong != NULL)
	{
		while (strcmp(&(*playlist)->userPlaylist.artist, thisArtist) != 0 && strcmp(&(*playlist)->userPlaylist.songTitle, thisSong) != 0)
		{
			playlist = &((*playlist)->pNext);
		}
	}

	last = &((*playlist)->pLast);
	next = &((*playlist)->pNext);

	last->pNext = next;
	next->pLast = last;
	free(&(*playlist));
}

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