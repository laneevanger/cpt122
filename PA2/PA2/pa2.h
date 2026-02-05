#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//Rating – an integer (1 – 5)

typedef struct duration
{
	unsigned int minutes;
	unsigned int seconds;
}Duration;

typedef struct record 
{
	char artist[40];
	char albumTitle[40];
	char songTitle[40];
	char genre[20];
	Duration songLength;
	unsigned int plays;
	int rating; 
}Record;

typedef struct node
{
	struct Node* pNext;
	struct Node* pLast;
	Record userPlaylist;
}Node;

enum Menu 
{
	LOAD = 1,
	STORE,
	DISPLAY,
	INSERT,
	DELETE,
	EDIT,
	SORT,
	RATE,
	PLAY,
	SHUFFLE,
	EXIT
};

void printMenu(void);
int isMenuInput(int choice);