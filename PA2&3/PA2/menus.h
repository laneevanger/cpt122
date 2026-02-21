#ifndef MENUS_H
#define MENUS_H

#include "record.h"

enum Menu
{
	LOAD = 1,
	STORE,
	DISPLAY,
	INSERT,
	DEL,
	EDIT,
	SORT,
	RATE,
	PLAY,
	SHUFFLE,
	EXIT
};

void printMenu(void);

int isMenuInput(int choice, int low, int high);

int findMenuInput(char list[][SMALLERMAGIC], int length);

#endif //MENUS_H