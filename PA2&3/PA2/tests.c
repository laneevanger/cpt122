#include "tests.h"

//insert
//starts with edge case of empty list (i dont even know if its possible)
int insertTest(Node* playlist)
{
	insertSong(&playlist);

	if (playlist != NULL && playlist->userPlaylist.artist[0] != '\0')
	{
		return 1;
	}
	return 0;
}

//delete
//makes empty list
int deleteTest(Node* playlist)
{
	//insertSong(&playlist);
	deleteSong(&playlist);

	if (playlist == NULL)
		return 1;

	return 0;
}

//shuffle
//empty list
//if it passes through it worked
int shuffleTest(Node* playlist, int order[])
{
	songShuffle(order, 1);

	if (order[0] == 1)
	{
		return 1;
	}

	return 0;
}