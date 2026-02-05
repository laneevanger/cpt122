#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef enum boolean
{
	FALSE, TRUE
} Boolean;
typedef struct contact
{
	char name[50];
	char phone[12]; // 18005557577
	char email[50];
	char title[20];
} Contact;
typedef struct node
{
	Contact data;
	struct node* pNext;
	struct node* pPrev; // this lab is now using two links
} Node;

