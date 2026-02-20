#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct stackNode
{
	int value;
	struct stackNode* next;
} StackNode;

typedef struct stack
{
	StackNode* top;
	int size;
} Stack;

int main(void)
{
	int maze[10][10] = { 0 };
	Stack* solution = { 0 };

	//n x m
	int n = 10;
	int m = 10;

	int start = rand() % n;

	maze[start][0] = 1;


}