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

int findMenuInput(char list[][SMALLERMAGIC], int length)
{
	int out;

	system("cls");

	for (int i = 0; i < length; i++)
	{
		printf("%d. %s\n", i + 1, list[i]);
	}

	printf("%d. Cancel\n", length + 1);

	do
	{
		printf("Choice: ");
		scanf("%d", &out);
	} while (isMenuInput(out, 1, length + 1) == 0);

	return out - 1;
}