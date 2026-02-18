#include "load.h"

//assumes playlist is big enough, files pretty small so shouldnt be a problem
int loadSongs(FILE* file, Node** playlist)
{
	Record newRecord = { 0 };
	char line[LITERALLYMAGICNUMBER];
	char time[TIMEMAGIC];
	char firstName[LITERALLYMAGICNUMBER] = { 0 };
	char lastName[LITERALLYMAGICNUMBER] = { 0 };
	char* tok;
	int size = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		// kept comma in name
		if (strtok(line, "\"") == NULL)
		{
			tok = strtok(line, "\"");
			sscanf(tok, "%s, %s", &lastName, &firstName);
			strcat(firstName, " ");
			//150s big enough 100%
			strcat(firstName, lastName);
			strcpy(newRecord.artist, firstName);
		}
		//no comma in name
		else
		{
			tok = strtok(line, ",");
			strcpy(newRecord.artist, tok);

		}

		tok = strtok(NULL, ",");
		strcpy(newRecord.albumTitle, tok);

		tok = strtok(NULL, ",");
		strcpy(newRecord.songTitle, tok);

		tok = strtok(NULL, ",");
		strcpy(newRecord.genre, tok);

		tok = strtok(NULL, ",");
		sscanf(tok, "%d:%d", &newRecord.songLength.minutes, &newRecord.songLength.seconds);

		tok = strtok(NULL, ",");
		newRecord.plays = atoi(tok);

		tok = strtok(NULL, ",");
		newRecord.rating = atoi(tok);

		size++;

		Node* newNode = makeNode(newRecord);

		if (playlist != NULL)
		{
			(*playlist)->pLast = newNode;
			newNode->pNext = playlist;
			playlist = &((*playlist)->pLast);
		}
		else
		{
			playlist = &newNode;
		}

	}

	return size;
}