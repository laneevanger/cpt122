#pragma once

#include <iostream>
#include <string>

enum Menu
{
	LOADCLASS = 1,
	LOADMASTER,
	STOREMASTER,
	DISPLAYMASTER,
	EDIT,
	REPORT,
	EXIT
};

void printMenu(void);

//inclusive
int isMenuInput(int choice, int low, int high);

//int findMenuInput(char list[][SMALLERMAGIC], int length)