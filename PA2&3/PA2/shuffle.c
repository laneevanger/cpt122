#include "shuffle.h"

//horrible way to do this, but you cant say its not random lmao
void songShuffle(int order[], int length)
{
	int newNumber = 0;
	int found = 0;

	//if(order != NULL)
	
	for (int i = 0; i < length; i++)
	{
		order[i] = 0;
	}

	for (int i = 0; i < length; i++)
	{
		do
		{
			found = 0;
			newNumber = rand() % length;

			for (int k = 0; k < i; k++)
			{
				if (order[k] == newNumber)
				{
					found = 1;
				}
			}

		} while (found == 0);
		order[i] = newNumber;
	}
}