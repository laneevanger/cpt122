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

//broken
void worstSleep(FitbitData list[], char out[])
{
    int range[660] = { 0 };
    char curStart[10] = { 0 };
    char curEnd[10] = { 0 };
    char maxStart[10] = { 0 };
    char maxEnd[10] = { 0 };
    int cTotal = 0; 
    int nTotal = 0; 
    int isStart = 0;

    for (int i = 0; i < 480; i++)
    {
        if (i < 180)
        {
            range[i] = 1260 + i;
        }
        else
        {
            range[i] = i - 180;
        }
    }

    for (int i = 0; i < 660; i++)
    {
        if (list[range[i]].sleepLevel > 1)
        {
            if (isStart == 0) 
            {
                strcpy(curStart, list[range[i]].minute);
                isStart = 1;
            }
            strcpy(curEnd, list[range[i]].minute);
            nTotal += list[range[i]].sleepLevel;
        }
        else 
        {
            if (isStart == 1 && nTotal > cTotal)
            {
                cTotal = nTotal;
                strcpy(maxStart, curStart);
                strcpy(maxEnd, curEnd);
            }
            nTotal = 0;
            isStart = 0;
        }
    }

    if (isStart == 1 && nTotal > cTotal)
    {
        cTotal = nTotal;
        strcpy(maxStart, curStart);
        strcpy(maxEnd, curEnd);
    }

    strcat(out, maxStart);
    strcat(out, " - ");
    strcat(out, maxEnd);
}

double avgHeartrate(FitbitData list[])
{
	double total = 0;
	double entries = 0;

	for (int i = 0; i < 1440; i++)
	{
		if (list[i].heartRate < 1000 && list[i].heartRate > 0)
		{
			total += list[i].heartRate;
			entries++;
		}
	}
	return total / entries;
}