#include "findSong.h"

//either can return null
void findSong(Node* list, char* artist, char* song)
{
	Node* headptr = list;
	char thisArtist[LITERALLYMAGICNUMBER] = 0;
	char thisSong[LITERALLYMAGICNUMBER] = 0;
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