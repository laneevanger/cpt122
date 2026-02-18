#include "store.h"

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