#include "tests.h"

Node* headptr = {0};
Record testRecord = {0};
int order[1] = {0};

//insert
//starts with edge case of empty list (i dont even know if its possible)
int insertTest(Node* playlist)
{
	insertSong(&playlist);

	if(playlist->userPlaylist.artist != NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//delete
//makes empty list
int deleteTest(Node* playlist)
{
	deleteSong(&playlist);

	if (playlist == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//shuffle
//empty list
//if it passes through it worked
int shuffleTest(Node* playlist)
{
	songShuffle(order, 20);

	return 1;
}