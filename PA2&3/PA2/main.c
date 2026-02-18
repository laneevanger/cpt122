#include "record.h"
#include "modify.h"
#include "menus.h"
#include "play.h"

int main(void)
{
	Node playlist[LITERALLYMAGICNUMBER] = {0};
	int order[LITERALLYMAGICNUMBER] = {0};
	int size = 0;
	int valid = 0;
	int menuChoice = 0;
	int exit = 1;

	srand((unsigned)time(NULL));

	//no shuffle play
	for (int i = 0; i < LITERALLYMAGICNUMBER; i++)
	{
		order[i] = i + 1;
	}

	FILE* inputStream = fopen("musicPlayListCopy.csv", "r");
	FILE* outputStream = fopen("musicPlayListCopy.csv", "w");

	valid = 0;
	if (playlist[0].userPlaylist.artist == NULL)
	{
		while (exit)
		{
			do
			{
				system("cls");
				printMenu();
				printf("1. Load\n");
				printf("2. Exit\n\n");
				scanf("%d", &menuChoice);

			} while (menuChoice > 2 && menuChoice < 1);

			//load
			if (menuChoice == 1)
			{
				size = loadSongs(inputStream, &playlist);
			}
			//exit
			else
			{
				printf("Exiting. . .\n");
				exit = 0;
			}
		}
		
	}
	else
	{
		while (exit)
		{
			do
			{
				system("cls");
				printMenu();
				scanf("%d", &menuChoice);
				valid = isMenuInput(menuChoice, LOAD, EXIT);
			} while (valid != 1);

			switch (menuChoice)
			{
			case LOAD:
				size = loadSongs(inputStream, &playlist);
				break;

			case STORE:
				storePlaylist(playlist, outputStream);
				break;

			case DISPLAY:
				displaySong(playlist);
				break;

			case INSERT:
				insertSong(&playlist);
				size++;
				break;

			case DEL:
				deleteSong(&playlist);
				size--;
				break;

			case EDIT:
				editSong(playlist);
				break;

			case SORT:
				songSort(playlist, size);
				break;

			case RATE:
				rateSong(playlist);
				break;

			case PLAY:
				songPlay(playlist, order, size);
				break;

			case SHUFFLE:
				songShuffle(order, size);
				break;

			case EXIT:
				printf("Exiting. . .\n");
				exit = 0;
				break;
			}
		}

	}
	fclose(inputStream);
	fclose(outputStream);
}