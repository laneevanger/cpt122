#include "pa2.h"

int main(void)
{
	Node* headPtr;
	int valid = 0;
	int menuChoice = 0;
	int exit = 1;

	do
	{
		system("cls");
		printMenu();
		scanf("%d", &menuChoice);
		//check for non int input
		valid = isMenuInput(menuChoice);
	} while (valid != 1);

	valid = 0;
	while (exit)
	{
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