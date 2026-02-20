#include "play.h"

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

//either can return null
void findSong(Node* list, char* artist, char* song)
{
	Node* headptr = list;
	char thisArtist[LITERALLYMAGICNUMBER] = {0};
	char thisSong[LITERALLYMAGICNUMBER] = {0};
	//150 items at 50 long, good enough for me
	char allArtists[LITERALLYMAGICNUMBER][SMALLERMAGIC] = { 0 };
	char allSongs[LITERALLYMAGICNUMBER][SMALLERMAGIC] = { 0 };
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
			if (strcmp(list->userPlaylist.artist, allArtists[i]) == 0)
			{
				found = 1;
			}
		}
		if (found == 0)
		{
			strcpy(allArtists[aLength], list->userPlaylist.artist);
		}
		list = list->pNext;
		aLength++;
	}

	aMenu = findMenuInput(allSongs, aLength);
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

		sMenu = findMenuInput(allSongs, sLength);
		strcpy(thisSong, allSongs[sMenu]);

		if (sMenu != sLength)
		{
			strcpy(artist, thisArtist);
			strcpy(song, thisSong);
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


//load
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

	while(fgets(line, sizeof(line), file) != NULL && playlist != NULL)
	{
		//kept comma in name
		if(strtok(line, "\"") == NULL)
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
			*playlist = newNode;
		}
		else
		{
			playlist = &newNode;
		}

	}

	return size;
}


//store
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


//display
void displaySong(Node* list)
{
	Node* headptr = list;
	char thisArtist[LITERALLYMAGICNUMBER] = {0};
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
			if (found == 0)
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


//delete
void deleteSong(Node** playlist)
{
	char thisArtist[LITERALLYMAGICNUMBER] = { 0 };
	char thisSong[LITERALLYMAGICNUMBER] = { 0 };
	Node* last = { 0 };
	Node* next = { 0 };

	findSong(*playlist, thisArtist, thisSong);

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


//edit
//rating and artist unfinished
//not to specification, better than specification
void editSong(Node* playlist)
{
	char thisArtist[LITERALLYMAGICNUMBER] = { 0 };
	char thisSong[LITERALLYMAGICNUMBER] = { 0 };
	Node* last = { 0 };
	Node* next = { 0 };
	char change[SMALLERMAGIC];
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

//sort
void songSort(Node* playlist, int length)
{
	Node* headptr = playlist;
	Node* next = playlist->pNext;
	Node* cur = playlist;
	Record hold = { 0 };
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


//rate
void rateSong(Node* playlist)
{
	char thisSong[SMALLERMAGIC];
	char thisArtist[SMALLERMAGIC];
	int rating = 0;

	findSong(playlist, thisArtist, thisSong);

	if(thisArtist != NULL && thisSong != NULL)
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

//play
void songPlay(Node* playlist, int order[], int length)
{
	int currentPos = 1;
	int currentSong = 0;

	while (currentSong < length)
	{
		while (order[currentSong] != currentPos)
		{
			if (currentPos < order[currentSong])
			{
				playlist = playlist->pLast;
				currentPos--;
			}
			else
			{
				playlist = playlist->pNext;
				currentPos++;
			}
		}

		system("cls");
		printf("Now playing:\n");
		printf("%s\n", playlist->userPlaylist.songTitle);
		printf("%s\n", playlist->userPlaylist.albumTitle);
		printf("%s\n", playlist->userPlaylist.artist);
		printf("%s\n", playlist->userPlaylist.genre);
		printf("%d:%d\n", playlist->userPlaylist.songLength.minutes, playlist->userPlaylist.songLength.seconds);
		printf("Plays:%d, Rating: %d \n", playlist->userPlaylist.plays, playlist->userPlaylist.rating);
		Sleep(3000);
	}
}


//shuffle
//horrible way to do this, but you cant say its not random lmao
void songShuffle(int order[], int length)
{
	int newNumber = 0;
	int found = 0;

	//if(order != NULL)

	for (int i = 0; i < length; i++)
	{
		order[i] = 0;
	}

	for (int i = 0; i < length; i++)
	{
		do
		{
			found = 0;
			newNumber = rand() % length;

			for (int k = 0; k < i; k++)
			{
				if (order[k] == newNumber)
				{
					found = 1;
				}
			}

		}while (found == 0);
		order[i] = newNumber;
	}
}


//insert
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

