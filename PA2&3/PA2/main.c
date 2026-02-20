#ifndef MAIN_C
#define MAIN_C

#include "record.h"
#include "modify.h"
#include "menus.h"
#include "play.h"
#include "tests.h"

//very broke
int main(void)
{
	Node* playlist = {0};
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

	//tests

	Node* testptr = { 0 };
	Record testRecord = { 0 };
	int testOrder[1] = { 0 };

	//insertTest();

	//deleteTest();

	//shuffleTest();

	//tests

	//ascii
	printf("   _____                      ____  __                     \n");
	printf("  / ___/____  ____  ____ _   / __ \\/ /___ ___  _____  _____\n");
	printf("  \\__ \\/ __ \\/ __ \\/ __ `/  / /_/ / / __ `/ / / / _ \\/ ___/\n");
	printf(" ___/ / /_/ / / / / /_/ /  / ____/ / /_/ / /_/ /  __/ /    \n");
	printf("/____/\\____/_/ /_/\\__, /  /_/   /_/\\__,_/\\__, /\\___/_/\n");
	printf("	   	 /____/                 /____/\n\n");

	system("pause");

	FILE* inputStream = fopen("musicPlayListCopy.csv", "r");
	FILE* outputStream = fopen("musicPlayListCopy.csv", "w");

	valid = 0;
	//empty playlist
	if(playlist->userPlaylist.artist == NULL)
	{
		while (exit)
		{
			do
			{
				system("cls");
				printf("1. Load\n");
				printf("2. Exit\n\n");
				scanf("%d", &menuChoice);

			} while (menuChoice > 2 && menuChoice < 1);

			//load
			if (menuChoice == 1)
			{
				size = loadSongs(inputStream, &playlist);
				system("cls");
				printf("Loaded\n");
				system("pause");
			}
			//exit
			else
			{
				printf("Exiting. . .\n");
				exit = 0;
			}
		}
		
	}
	//populated playlist
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
				system("cls");
				printf("Loaded\n");
				system("pause");
				break;

			case STORE:
				storePlaylist(playlist, outputStream);
				system("cls");
				printf("Stored\n");
				system("pause");
				break;

			case DISPLAY:
				displaySong(playlist);
				system("pause");
				break;

			case INSERT:
				insertSong(&playlist);
				system("cls");
				printf("Inserted\n");
				system("pause");
				size++;
				break;

			case DEL:
				deleteSong(&playlist);
				system("cls");
				printf("Deleted\n");
				system("pause");
				size--;
				break;

			case EDIT:
				editSong(playlist);
				system("cls");
				printf("Edited\n");
				system("pause");
				break;

			case SORT:
				songSort(playlist, size);
				system("cls");
				printf("Sorted\n");
				system("pause");
				break;

			case RATE:
				rateSong(playlist);
				system("cls");
				printf("Rating Changed\n");
				system("pause");
				break;

			case PLAY:
				songPlay(playlist, order, size);
				break;

			case SHUFFLE:
				songShuffle(order, size);
				system("cls");
				printf("Shuffled\n");
				system("pause");
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

#endif //MAIN_C