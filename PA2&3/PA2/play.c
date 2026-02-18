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

void songSort(Node* playlist, int length)
{
	Node* headptr = playlist;
	//Node* last = playlist->pLast;
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

		} while (found == 0);
		order[i] = newNumber;
	}
}

