#include "insert.h"

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