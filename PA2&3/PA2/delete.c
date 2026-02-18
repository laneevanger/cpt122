#include "delete.h"

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