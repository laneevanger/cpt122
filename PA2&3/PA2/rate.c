#include "rate.h"

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