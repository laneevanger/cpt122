#ifndef PLAY_H
#define PLAY_H

#include "menus.h"
#include "record.h"

typedef struct node
{
	struct Node* pNext;
	struct Node* pLast;
	Record userPlaylist;
}Node;

Node* makeNode(Record playlist);
void findSong(Node* list, char* artist, char* song);
void displaySong(Node* list);
void songSort(Node* playlist, int length);
void rateSong(Node* playlist);
void songPlay(Node* playlist, int order[], int length);
void songShuffle(int order[], int length);

int loadSongs(FILE* file, Node** playlist);
void storePlaylist(Node* playlist, FILE* file);
void insertSong(Node** playlist);
void deleteSong(Node** playlist);
void editSong(Node* playlist);

#endif //PLAY_H