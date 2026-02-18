#ifndef PLAY_H
#define PLAY_H

#include "findSong.h"
#include "menus.h"
#include "record.h"

Node* makeNode(Record playlist);
void findSong(Node* list, char* artist, char* song);
void displaySong(Node* list);
void songSort(Node* playlist, int length);
void rateSong(Node* playlist);
void songPlay(Node* playlist, int order[], int length);
void songShuffle(int order[], int length);

#endif //PLAY_H