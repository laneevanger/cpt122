#include "play.h"
#include "menus.h"

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
	char allArtists[LITERALLYMAGICNUMBER][SMALLERMAGIC] = { 0 };
	char allSongs[LITERALLYMAGICNUMBER][SMALLERMAGIC] = { 0 };

	int aLength = 0;
	int sLength = 0;

	Node* cur = list;

	while (cur && aLength < LITERALLYMAGICNUMBER)
	{
		int found = 0;

		for (int i = 0; i < aLength; i++)
		{
			if (strcmp(cur->userPlaylist.artist, allArtists[i]) == 0)
			{
				found = 1;
			}
		}	

		if (found == 0)
		{
			strcpy(allArtists[aLength], cur->userPlaylist.artist);
			aLength++;
		}

		cur = cur->pNext;
	}

	int aMenu = findMenuInput(allArtists, aLength);
	if (aMenu == aLength)
	{
		artist[0] = '\0';
		song[0] = '\0';
		return NULL;
	}

	strcpy(artist, allArtists[aMenu]);

	cur = list;

	while (cur && sLength < LITERALLYMAGICNUMBER)
	{
		if (strcmp(cur->userPlaylist.artist, artist) == 0)
		{
			strcpy(allSongs[sLength], cur->userPlaylist.songTitle);
			sLength++;
		}
		cur = cur->pNext;
	}

	int sMenu = findMenuInput(allSongs, sLength);
	if (sMenu == sLength)
	{
		artist[0] = '\0';
		song[0] = '\0';
		return NULL;
	}

	strcpy(song, allSongs[sMenu]);
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

	//wont let file be loaded twice
	if (*playlist != NULL)
	{
		Node* headptr = *playlist;
		Node* temp;

		while (headptr != NULL)
		{
			temp = headptr;
			headptr = headptr->pNext;
			free(temp);
		}

		*playlist = NULL;
	}

	while(fgets(line, sizeof(line), file) != NULL)
	{
		//kept comma in name
		if (strchr(line, '"'))
		{
			tok = strtok(line, "\"");
			sscanf(tok, "%s %s", lastName, firstName);
			lastName[strlen(lastName) - 1] = '\0';
			strcat(firstName, " ");
			strcat(firstName, lastName);
			strcpy(newRecord.artist, firstName);

			//strtok(NULL, ",");
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

		if (*playlist != NULL)
		{
			newNode->pNext = *playlist;
			(*playlist)->pLast = newNode;
		}
		*playlist = newNode;

	}

	return size;
}


//store
void storePlaylist(Node* playlist, FILE* file)
{
	if (playlist != NULL && file != NULL)
	{
		//first entry
		fprintf(file, "%s,%s,", playlist->userPlaylist.artist, playlist->userPlaylist.albumTitle);
		fprintf(file, "%s,%s,", playlist->userPlaylist.songTitle, playlist->userPlaylist.genre);
		fprintf(file, "%d:%d,", playlist->userPlaylist.songLength.minutes, playlist->userPlaylist.songLength.seconds);
		fprintf(file, "%d,%d", playlist->userPlaylist.plays, playlist->userPlaylist.rating);
		fprintf(file, "\n");

		//all other entries
		while(playlist->pNext != NULL)
		{
			playlist = playlist->pNext;
			fprintf(file, "%s,%s,", playlist->userPlaylist.artist, playlist->userPlaylist.albumTitle);
			fprintf(file, "%s,%s,", playlist->userPlaylist.songTitle, playlist->userPlaylist.genre);
			fprintf(file, "%d:%d,", playlist->userPlaylist.songLength.minutes, playlist->userPlaylist.songLength.seconds);
			fprintf(file, "%d,%d", playlist->userPlaylist.plays, playlist->userPlaylist.rating);
			fprintf(file, "\n");
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
				aLength++;
			}
			list = list->pNext;
		}

		system("cls");
		for (int i = 0; i < aLength; i++)
		{
			printf("%d. %s\n", i + 1, allArtists[i]);
		}
		do
		{
			printf("Choice: ");
			scanf(" %d", &aMenu);
		} while (isMenuInput(aMenu, 0, aLength - 1) != 1);

		strcpy(thisArtist, allArtists[aMenu - 1]);

	}

	while (headptr != NULL)
	{
		if (choice == 1 || strcmp(headptr->userPlaylist.artist, thisArtist) == 0)
		{
			printf("%s, %s, ", headptr->userPlaylist.artist, headptr->userPlaylist.albumTitle);
			printf("%s, %s, ", headptr->userPlaylist.songTitle, headptr->userPlaylist.genre);
			printf("%d:%d, ", headptr->userPlaylist.songLength.minutes, headptr->userPlaylist.songLength.seconds);
			printf("%d,%d\n", headptr->userPlaylist.plays, headptr->userPlaylist.rating);
		}
		headptr = headptr->pNext;
	}
}


//delete
void deleteSong(Node** playlist)
{
	char thisArtist[LITERALLYMAGICNUMBER] = { 0 };
	char thisSong[LITERALLYMAGICNUMBER] = { 0 };
	Node* next = NULL;
	Node* last = NULL;
	Node* cur = NULL;

	findSong(*playlist, thisArtist, thisSong);

	cur = *playlist;

	if (thisArtist[0] != '\0' && thisSong[0] != '\0')
	{
		while (strcmp(cur->userPlaylist.artist, thisArtist) != 0 ||
			     strcmp(cur->userPlaylist.songTitle, thisSong) != 0)
		{
			cur = cur->pNext;
		}
	}

	next = cur->pNext;
	last = cur->pLast;

	if (cur->pLast != NULL)
	{
		last = cur->pNext;
	}	
	else
	{
		*playlist = cur->pNext;
	}

	if (cur->pNext != NULL)
	{
		next = cur->pLast;
	}
		
	free(cur);

}


//edit
//rating and artist unfinished
//not to specification, better than specification
void editSong(Node* playlist)
{
	char thisArtist[LITERALLYMAGICNUMBER] = { 0 };
	char thisSong[LITERALLYMAGICNUMBER] = { 0 };
	Node* last = NULL;
	Node* next = NULL;
	char change[SMALLERMAGIC];
	int choice = 0;

	findSong(playlist, thisArtist, thisSong);

	if (strlen(thisArtist) > 0 && strlen(thisSong) > 0)
	{
		while(strcmp(playlist->userPlaylist.artist, thisArtist) != 0 ||
			    strcmp(playlist->userPlaylist.songTitle, thisSong) != 0) 
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

	} while(isMenuInput(choice, 1, 8) == 0);

	if (choice < 8)
	{
		system("cls");
		switch (choice)
		{
		case 1:
			do
			{
				system("cls");
				printf("New Artist: ");
				scanf(" %49[^\n]", &playlist->userPlaylist.artist);
			} while (strchr(playlist->userPlaylist.artist, '"') != NULL ||
				         strchr(playlist->userPlaylist.artist, ',') != NULL);
			break;
		case 2:
			printf("New Album title: ");
			scanf(" %49[^\n]", &playlist->userPlaylist.albumTitle);
			break;
		case 3:
			printf("New Song title: ");
			scanf(" %49[^\n]", &playlist->userPlaylist.songTitle);
			break;
		case 4:
			printf("New Genre: ");
			scanf(" %49[^\n]", &playlist->userPlaylist.genre);
			break;
		case 5:
			printf("New Minutes: ");
			scanf("%d", &playlist->userPlaylist.songLength.minutes);
			printf("\nNew Seconds: ");
			scanf("%d", &playlist->userPlaylist.songLength.seconds);
			break;
		case 6:
			printf("New Number of plays: ");
			scanf("%d", &playlist->userPlaylist.plays);
			break;
		case 7:
			printf("New Number of Rating: ");
			scanf("%d", &playlist->userPlaylist.rating);
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
		system("cls");

		printf("1. Sort based on artist (A-Z)\n");
		printf("2. Sort based on album title (A-Z)\n");
		printf("3. Sort based on rating (1-5)\n");
		printf("4. Sort based on times played (Most to Least)\n");
		printf("5. Cancel\n\n");
		scanf("%d", &choice);

		system("cls");

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
				if (strcmp(cur->userPlaylist.artist, 
					  next->userPlaylist.artist) > 0)
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
				if (strcmp(cur->userPlaylist.albumTitle, 
					  next->userPlaylist.albumTitle) > 0)
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

		while(strcmp(playlist->userPlaylist.artist, thisArtist) != 0 ||
			    strcmp(playlist->userPlaylist.songTitle, thisSong) != 0) 
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
	Node* cur = playlist;

	for (int i = 0; i < length; i++)
	{
		Node* cur = playlist;

		for (int k = 1; k < order[i]; k++)
		{
			cur = cur->pNext;
		}

		system("cls");
		printf("Now playing:\n");
		printf("%s\n", cur->userPlaylist.songTitle);
		printf("%s\n", cur->userPlaylist.albumTitle);
		printf("%s\n", cur->userPlaylist.artist);
		printf("%s\n", cur->userPlaylist.genre);
		printf("%d:%d\n", cur->userPlaylist.songLength.minutes, playlist->userPlaylist.songLength.seconds);
		printf("Plays:%d, Rating: %d \n", cur->userPlaylist.plays, playlist->userPlaylist.rating);
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
			newNumber = rand() % length + 1;

			for (int k = 0; k < i; k++)
			{
				if (order[k] == newNumber)
				{
					found = 1;
				}
			}

		}while (found == 1);
		order[i] = newNumber;
	}
}


//insert
//same issue as edit
void insertSong(Node** playlist)
{
	Node* newNode = malloc(sizeof(Node));
	do
	{
		system("cls");
		printf("New Artist: ");
		scanf(" %49[^\n]", newNode->userPlaylist.artist);
	} while (strchr(newNode->userPlaylist.artist, '"') != NULL ||
		        strchr(newNode->userPlaylist.artist, ',') != NULL);

	system("cls");
	printf("New Album title: ");
	scanf(" %49[^\n]", newNode->userPlaylist.albumTitle);

	system("cls");
	printf("New Song title: ");
	scanf(" %49[^\n]", newNode->userPlaylist.songTitle);

	system("cls");
	printf("New Genre: ");
	scanf(" %49[^\n]", newNode->userPlaylist.genre);

	system("cls");
	printf("New Minutes: ");
	scanf("%d", &newNode->userPlaylist.songLength.minutes);

	printf("New Seconds: ");
	scanf("%d", &newNode->userPlaylist.songLength.seconds);

	system("cls");
	printf("New Number of plays: ");
	scanf("%d", &newNode->userPlaylist.plays);

	system("cls");
	printf("New Rating: ");
	scanf("%d", &newNode->userPlaylist.rating);

	newNode->pNext = *playlist;
	*playlist = newNode;
}

