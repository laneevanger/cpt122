#include "menus.h"

void printMenu(void)
{
	printf("1. Load\n");
	printf("2. Store\n");
	printf("3. Display\n");
	printf("4. Insert\n");
	printf("5. Delete\n");
	printf("6. Edit\n");
	printf("7. Sort\n");
	printf("8. Rate\n");
	printf("9. Play\n");
	printf("10. Shuffle\n");
	printf("11. Exit\n\n");
}

int isMenuInput(int choice, int low, int high)
{
	if (choice >= low && choice <= high)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int findMenuInput(static char list[][LITERALLYMAGICNUMBER], int length)
{
	int out = 0;

	system("cls");
	for (int i = 0; i < length; i++)
	{
		printf("%d. %s\n", i + 1, list[i]);

		if (length == i)
		{
			printf("%d. Cancel\n", i + 1);
		}
	}
	do
	{
		scanf("\nChoice: %d", &out);
	} while (isMenuInput(out, 0, length) != 1);

	return out - 1;
}