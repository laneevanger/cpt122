#include "pa2.h"

int main(void)
{
	Node list[LITERALLYMAGICNUMBER] = {0};
	int valid = 0;
	int menuChoice = 0;
	int exit = 1;

	valid = 0;
	if (list[0].userPlaylist.artist == NULL)
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

			//revist new menu code passouts
			switch (menuChoice)
			{
			case LOAD:
				break;

			case STORE:
				break;

			case DISPLAY:
				break;

			case INSERT:
				break;

			case DELETE:
				break;

			case EDIT:
				break;

			case SORT:
				break;

			case RATE:
				break;

			case PLAY:
				break;

			case SHUFFLE:
				break;

			case EXIT:
				printf("Exiting. . .\n");
				exit = 0;
				break;
			}
		}

	}
	
}