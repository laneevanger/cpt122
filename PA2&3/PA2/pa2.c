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

int isMenuInput(int choice, int low, int high)
{
	if (choice >= low && choice <= high)
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

//assumes playlist is big enough, files pretty small so shouldnt be a problem
void loadPlaylist(FILE* file, Node** playlist)
{
	Record newRecord = { 0 };
	char line[LITERALLYMAGICNUMBER];
	char time[TIMEMAGIC];
	char firstName[LITERALLYMAGICNUMBER] = {0};
	char lastName[LITERALLYMAGICNUMBER] = {0};
	char* tok;

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
			scanf("New Artist (no , or \"): %s", playlist->userPlaylist.artist);
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

void rateSong(Node* playlist)
{
	char thisSong[SMALLERMAGIC];
	char thisArtist[SMALLERMAGIC];
	int rating = 0;

	findSong(playlist, thisArtist, thisSong);

	if (thisArtist != NULL && thisSong != NULL)
	{
		system("cls");
		printf("What would you like to rate the song:\n");
		scanf(" %d", &rating);

		while (strcmp(playlist->userPlaylist.artist, thisArtist) != 0 && strcmp(playlist->userPlaylist.songTitle, thisSong) != 0)
		{
			playlist = playlist->pNext;
		}

		if (rating < 1)
		{
			playlist->userPlaylist.rating = 1;
		}
		else if (rating > 5)
		{
			playlist->userPlaylist.rating = 5;
		}
		else
		{
			playlist->userPlaylist.rating = rating;
		}
	}

}

void deleteSong(Node** playlist)
{
	char thisArtist[LITERALLYMAGICNUMBER] = {0};
	char thisSong[LITERALLYMAGICNUMBER] = {0};
	Node* last = {0};
	Node* next = {0};

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

//look for timeout command
void songPlay(Node* playlist, int order[], int length)
{
	int currentPos = 1;
	int currentSong = 1;

	while (currentSong <= length)
	{
		while()
		{

		}
	}

	//Sleep(3000); pauses for 3 seconds (miliseconds)
}

//either can return null
void findSong(Node* list, char* artist, char* song)
{
	Node* headptr = list;
	char thisArtist[LITERALLYMAGICNUMBER] = 0;
	char thisSong[LITERALLYMAGICNUMBER] = 0;
	//150 items at 50 long, good enough for me
	char allArtists[LITERALLYMAGICNUMBER][SMALLERMAGIC] = {0};
	char allSongs[LITERALLYMAGICNUMBER][SMALLERMAGIC] = {0};
	int aLength = 0;
	int sLength = 0;
	int aMenu = 0;
	int sMenu = 0;
	int found = 0;

	//will never hit magic break case
	while (list != NULL && aLength < LITERALLYMAGICNUMBER)
	{
		found = 0;
		for (int i = 0; i < aLength; i++)
		{
			if(strcmp(list->userPlaylist.artist, allArtists[i]) == 0)
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

	aMenu = findMenuInput(allSongs, sLength);
	if (aMenu != aLength)
	{
		strcpy(thisArtist, allArtists[findMenuInput(allArtists, aLength)]);

		//assumes no duplicate songs but like it wouldnt matter anyways
		while (headptr != NULL && sLength < LITERALLYMAGICNUMBER)
		{
			for (int i = 0; headptr != NULL && sLength < LITERALLYMAGICNUMBER; i++)
			{
				if (strcmp(headptr->userPlaylist.artist, thisArtist) == 0)
				{
					strcpy(allSongs[i], headptr->userPlaylist.songTitle);
					sLength++;
				}
				headptr = headptr->pNext;
			}
		}
		strcpy(thisSong, allSongs[sMenu]);
		if (sMenu != sLength)
		{
			artist = thisArtist;
			song = thisSong;
		}
		else
		{
			artist = NULL;
			song = NULL;
		}
	}
	else
	{
		artist = NULL;
		song = NULL;
	}
	
}

int findMenuInput (static char list[][LITERALLYMAGICNUMBER], int length)
{ 
	int out = 0;

	system("cls");
	for(int i = 0; i < length; i++)
	{
		printf("%d. %s\n", i + 1, list[i]);

		if (length == i)
		{
			printf("%d. Exit\n", i + 1);
		}
	}
	do
	{ 
		scanf("\nChoice: %d", &out);
	} while (isMenuInput(out, 0, length) != 1);

	return out - 1;
}