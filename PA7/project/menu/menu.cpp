#include "..\menu\menu.hpp"

//change

void printMenu(void)
{
	std::cout << "1.Load Classes" << std::endl;
    std::cout << "2.Load Master" << std::endl;
    std::cout << "3.Store Master " << std::endl;
    std::cout << "4.Mark Absences " << std::endl;
    std::cout << "5.Edit Absences" << std::endl;
    std::cout << "6.Generate Report" << std::endl;
    std::cout << "7.Exit " << std::endl;
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

/*
//for bonus
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
    */