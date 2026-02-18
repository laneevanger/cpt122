#include "play.h"

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