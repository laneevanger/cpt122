#include "consts.h"

#ifndef RECORD_H
#define RECORD_H

//Rating – an integer (1 – 5)

typedef struct duration
{
	unsigned int minutes;
	unsigned int seconds;
}Duration;

typedef struct record 
{
	char artist[SMALLERMAGIC];
	char albumTitle[SMALLERMAGIC];
	char songTitle[SMALLERMAGIC];
	char genre[SMALLERMAGIC];
	Duration songLength;
	unsigned int plays;
	int rating; 
}Record;

#endif