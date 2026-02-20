#include "tests.h"

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
int shuffleTest(Node* playlist, int order[])
{
	songShuffle(order, 1);

	return 1;
}