#include "pa1.h"

int isDuplicate(FitbitData list[], int index)
{
	if (list[index].minute[0] != '\0')
	{
		return 1;
	}

	return 0;
}

int timeToIndex(char time[])
{
	int hours = 0;
	int minutes = 0;
	int mOnes = 0;
	int sOnes = 0;

	//8:48
	for (int i = 0; i < 5; i++)
	{
		if (time[i] != ':')
		{
			if (i == 1 && mOnes == 1)
			{
				hours = hours * 10 + (time[i] - '0') * 60;
			}
			else if (i == 1 || i == 0)
			{
				hours += (time[i] - '0') * 60;
				mOnes++;
			}
			if ((i == 3 || i == 4) && sOnes == 1)
			{
				minutes = minutes * 10 + (time[i] - '0');
			}
			else if (i == 2 || i == 3)
			{
				minutes += (time[i] - '0');
				sOnes++;
			}
		}
		
	}
	return hours + minutes;
}