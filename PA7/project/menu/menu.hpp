#pragma once

#include <iostream>
#include <string>

enum Menu
{
	LOADCLASS = 1,
	LOADMASTER,
	STOREMASTER,
	MARKABSENCES,
	EDIT,
	REPORT,
	EXIT
};

void printMenu(void);

//inclusive
int isMenuInput(int choice, int low, int high);